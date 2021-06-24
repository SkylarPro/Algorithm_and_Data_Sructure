// Реализация очереди
// Created by Виктор Кумпан on 05.03.2021.
// queue

#include <iostream>
#include <vector>

struct Queue{
    std::vector<long long> body;
    void push(long long num);
    void remove();
};

void Queue::push(long long num){
    body.push_back(num);
}

void Queue::remove(){
    if (body.empty()) return;
    else{
        std::cout << body[0] << '\n';
        body.erase(body.begin());
    }
}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("queue.in", "r", stdin);
    freopen("queue.out", "w", stdout);
    Queue s;
    long long num;
    std::string str;
    while ((getline(std::cin, str))){
        if (str.empty()) break;
        if (str.substr(0,str.find(' '))=="+"){
            num = stoi(str.substr(str.find(' ')+1,str.size()));
            s.push(num);
        } else if (str.substr(0,str.find(' '))=="-"){
            s.remove();
        }
    }
    return 0;
}

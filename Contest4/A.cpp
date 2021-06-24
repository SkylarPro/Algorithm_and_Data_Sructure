// Реализация стека
// Created by Виктор Кумпан on 05.03.2021.
// stack

#include <iostream>
#include <vector>

struct Stack {
    void remove();
    void push(long long num);
    std::vector<long long> body;
};

void Stack::remove(){
    if (body.empty())
        return;
    else{
        std::cout << body[body.size()-1]<<"\n";
        body.pop_back();
    }
}

void Stack::push(long long num){
    body.push_back(num);
}


int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("sum.in", "r", stdin);
    freopen("sum.out", "w", stdout);
    Stack s;
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
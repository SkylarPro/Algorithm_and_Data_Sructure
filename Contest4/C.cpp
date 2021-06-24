// Правильная скобочная последовательность
// Created by Виктор Кумпан on 05.03.2021.
// brackets

#include <iostream>
#include  <vector>


struct Stack{
    std::vector<char> body;
    void push(char c);
    bool open(char c);
    bool close(char c);
};

void Stack::push(char c){
    body.push_back(c);
};

bool Stack::open(char c){
    return ((c == '(') || (c == '['));
};

bool Stack::close(char c){
    return ((body[body.size() - 1]=='(' && c == ')') || (body[body.size() - 1]=='[' && c == ']'));
};

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("brackets.in", "r", stdin);
    freopen("brackets.out", "w", stdout);
    std::string str;
    while(getline(std::cin,str)){
        if (str.empty()) break;
        Stack s;
        for(char c: str){
            if (s.open(c))
                s.push(c);
            else if (s.body.size() > 0 && s.close(c))
                s.body.pop_back();
            else{
                s.push(c);
                break;
            }
        }
        std::cout << (s.body.empty() ? "YES": "NO") << '\n';
    }
    return 0;
}


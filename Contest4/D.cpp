// Постфиксная запись
// Created by Виктор Кумпан on 15.03.2021.
// postfix
#include <iostream>
#include <vector>


int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("postfix.in", "r", stdin);
    freopen("postfix.out", "w", stdout);
    std::string str;
    getline(std::cin,str);
    std::vector<long long> s;
    for (char c: str){
        if (int(c)>=48 && int(c)<=57){
            int num = int(c) - 48;
            s.push_back(num);
        }
        else if (c == '+') {
            s[s.size() - 2] = s[s.size() - 2] + s[s.size() - 1];
            s.pop_back();
        }
        else if (c == '-'){
            s[s.size()-2] = s[s.size()-2] - s[s.size()-1];
            s.pop_back();
        }
        else if (c == '*'){
            s[s.size() - 2] = s[s.size()-2] * s[s.size()-1];
            s.pop_back();
        }
    }
    std::cout << s[0];
    return 0;
}
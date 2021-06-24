//A+B^2
// Created by Виктор Кумпан on 11.02.2021.
//aplusbb

#include <iostream>
#include <cmath>


int main() {
    long long num1, num2;
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("aplusbb.in", "r", stdin);
    freopen("aplusbb.out", "w", stdout);
    std::cin >> num1 >> num2;
    long long answer = num1 + pow(num2,2);
    std::cout << answer;
    return 0;
}


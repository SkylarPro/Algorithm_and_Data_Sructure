
// A+B

#include <iostream>


int main() {
    int num1,num2;
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("aplusb.in", "r", stdin);
    freopen("aplusb.out", "w", stdout);
    std::cin >> num1 >> num2;
    std::cout << num1 + num2;
    return 0;
}

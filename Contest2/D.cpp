//
// Created by Виктор Кумпан on 15.02.2021.
//antiqs

#include <iostream>
#include <vector>

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("antiqs.in", "r", stdin);
    freopen("antiqs.out", "w", stdout);
    int size; std::cin >> size;
    std::vector <int> arr;
    arr.resize(size);
    for (int i = 1; i <=size; i++){
        arr[i-1] = i;
    }
    for (int i = 2; i<size;i++)
        std::swap(arr[i],arr[i/2]);

    for(int i : arr)
        std:: cout << i<< " ";

    return 0;
}
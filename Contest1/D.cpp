//Сортировка вставкой
// Created by Виктор Кумпан on 13.02.2021.
// smollsort

#include <iostream>

using namespace  std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("inversions.in", "r", stdin);
    freopen("inversions.out", "w", stdout);
    int size;
    cin >> size;
    int start_array[size];
    int num;
    int count = 0;
    for (int i = 0; i <size; i ++){
        cin >> num;
        start_array[i] = num;
        if (i>0) {
            int  key = start_array[i];
            int j = i - 1;
            while ((j > -1) and (start_array[j]>key)){
                start_array[j+1] = start_array[j];
                count++;
                j-=1;
            }
            start_array[j+1] = key;
        }
    }
    for(int i: start_array){
        std::cout << i <<" ";
    }
}

// Цифровая сортировка
// Created by Виктор Кумпан on 26.02.2021.
//

#include <iostream>
#include <string>

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("radixsort.in", "r", stdin);
    freopen("radixsort.out", "w", stdout);
    int n; int m; int k;
    std::cin>>n>>m>>k;
    std::string arr[n];
    std::string sortArr[n];

    for (int i = 0; i <n; i++) std::cin>>arr[i];
    //RadixSort
    for (int j = 0; j < k; j++){
            int numArr[26];
            for (int i = 0; i  < 26; i++) numArr[i] = 0;
            for (int i = 0; i < n; i++) numArr[int(arr[i][m-j-1])-97]++;
            for (int i = 1; i  < 26; i++) numArr[i] += numArr[i-1] ;
            for (int i = n - 1; i > -1; i--) {
                numArr[int(arr[i][m-j-1])-97]--;
                sortArr[numArr[int(arr[i][m-j-1])-97]] = arr[i]; // проблема в том, что он ссылается на больший индекс,
                // возможно надо пересмотерть 21 строчку с инициализацией.
            }
            for(int i = 0;i<n;i++) arr[i]=sortArr[i];
        }

    for (int i = 0; i<n; i++) std::cout<<sortArr[i]<<"\n";
    return 0;
}


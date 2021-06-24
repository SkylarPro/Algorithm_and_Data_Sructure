// Merge Sort
// Created by Виктор Кумпан on 14.02.2021.
//
#include <iostream>
#include <cmath>

using namespace std;

void Merge(long start_array[], int p, int q, int n){
    long fslice[q - p + 2];
    long sslice[n - q + 1];
    long maxx =pow(11,9);
    fslice[q - p + 1] = maxx;
    sslice[n - q] = maxx;

    for (int i = 0; i < q - p + 1; i ++)
        fslice[i] = start_array[p+i];

    for (int i = 0; i < n - q;i++)
        sslice[i] = start_array[q+i+1];

    int i = 0;
    int j = 0;
    for (int k = p; k < n+1; k++){
        if (fslice[i] >= sslice[j]){
            start_array[k] = sslice[j];
            j++;
        }else {
            start_array[k] = fslice[i];
            i++;
        }
    }
}

void mergeDistr(long start_array[], int p, int n){
    if (p < n) {
        int q = (n+p)/2;
        mergeDistr(start_array, p, q);
        mergeDistr(start_array, q+1, n);
        Merge(start_array,p,q,n);
    }
    }

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    int size; cin >> size;
    long start_array[size];
    for (int i = 0 ; i <size; i++){
        cin >> start_array[i];
    }
    mergeDistr(start_array, 0, size - 1);
    for(long i: start_array)
        cout << i << " ";
    return 0;
}
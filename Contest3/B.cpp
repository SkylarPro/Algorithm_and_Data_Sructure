// Сортировка кучей
// Created by Виктор Кумпан on 26.02.2021.
// sort

#include <iostream>
#include <vector>

int max_heap(int* arr, int i,int n){
    int left = i*2 + 1;
    int right = i*2 + 2;
    int largest = i;
    if (left < n && arr[left] >= arr[i]) largest = left;
    if (right < n && arr[right]>=arr[largest]) largest = right;
    if (largest!=i){
        std::swap(arr[i],arr[largest]);
        max_heap(arr, largest, n);
    }
    return 0;
}

int build_heap(int* arr,int n){
    for (int i = n/2 - 1; i>-1 ; i--) max_heap(arr,i,n);
    return 0;
}


int heapsort(int* arr,int n){
    build_heap(arr,n);
    for(int i = n - 1;i > -1; i--){
        std::swap(arr[0],arr[i]);
        max_heap(arr,0, i);
    }
    return 0;
}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    int n;
    std::cin>>n;
    int *arr = new int[n];
    for (int i = 0;i<n;i++) std::cin>>arr[i];
    heapsort(arr,n);
    for(int i =0; i< n;i++) std::cout<<arr[i]<<" ";
    return 0;
}


//Кучи. Является ли неубывающей пирамидой?
// Created by Виктор Кумпан on 26.02.2021.
//isheap


#include <iostream>
#include <vector>

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("isheap.in", "r", stdin);
    freopen("isheap.out", "w", stdout);
    int n;
    std::cin>>n;
    std::vector<long long> arr;
    for (int i = 0; i<n; i++){
        long long temp; std::cin>> temp;
        arr.push_back(temp);
    }
    for (int i = 0; i<n/2; i+=1){
        int l = 2*i + 1;
        int r = 2*i + 2;
        if (l < arr.size() && arr[l] < arr[i]){
            std::cout<<"NO"; return 0;
        }
        if (r < arr.size() && arr[r] < arr[i]){
            std::cout<<"NO"; return 0;
        }
    }
    std::cout<<"YES";
    return 0;
}
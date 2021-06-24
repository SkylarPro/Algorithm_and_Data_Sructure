//K-ая порядковая статистика (проходит за O(n))
// Created by Виктор Кумпан on 18.02.2021.
// kth

#include <iostream>
#include <cmath>
#include <random>


std:: random_device random_device;
std::mt19937 generator(random_device());


int Partition(int *arr, int p,int n,int x){
    int i = p;
    int count = p;
    int maxx = 0;
    for (int j = p; j < n;j ++){
        if (arr[j] < x) {
            std::swap(arr[i], arr[j]);
            i++;
        }
        if (arr[j] == x) count++;
        if (arr[j]>x) maxx++;
    }
    if (((n - p ) == 2) and (arr[p]==arr[p+1])) return (count + i) / 2;
    // случаи для финального разбиения одинаковых чиселок [1,1] [2,2]
    if (i == p and count - 1 > p and maxx!=0) return ((count + i) / 2) - 1;
    // повторяющиеся элементы, но не максимальные [1,1,2,3,4,5]
    if (i == p and count - 1 > p and maxx==0) return ((count + i) / 2);
    // когда в массиве одни повторяющиеся элементы [1,1,1,1,1]
    return i;
}

int Randomized_Partition(int *arr, int p, int n, int k) {
    if (n - p == 1) {
        return arr[k];
    }
    std::uniform_int_distribution<> distribution(p, n-1);
    int x = arr[distribution(generator)];
    int mid = Partition(arr, p, n, x);
    if (k < mid) {
        return Randomized_Partition(arr,p,mid,k);
    }
    else {
        return Randomized_Partition(arr,mid,n,k);
    }
}


int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("kth.in", "r", stdin);
    freopen("kth.out", "w", stdout);
    int n; int k;
    int A = 0; int B = 0; int C = 0;
    int a1; int a2;
    std::cin >>n >> k;
    int *arr = new int[n];
    std::cin >> A >> B >> C >> a1 >> a2;
    arr[0] = a1; arr[1] = a2;
    for (int i = 2 ; i<n; i ++){
        arr[i] = A*arr[i-2] + B*arr[i-1] + C;
    }
    std::cout << Randomized_Partition(arr, 0, n, k - 1);
    delete[] arr;
    return 0;
}
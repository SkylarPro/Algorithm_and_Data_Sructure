// Число инверсий
// Created by Виктор Кумпан on 14.02.2021.
// inversions
#include <iostream>
#include <cmath>

using namespace std;

long long Merge(long start_array[], long p, long q, long n, long long count) {
    long fslice[q - p + 2];
    long sslice[n - q + 1];
    long maxx = pow(11, 9);
    fslice[q - p + 1] = maxx;
    sslice[n - q] = maxx;

    for (long i = 0; i < q - p + 1; i++)
        fslice[i] = start_array[p + i];

    for (long i = 0; i < n - q; i++)
        sslice[i] = start_array[q + i + 1];

    long i = 0;
    long j = 0;
    for (long k = p; k < n + 1; k++) {
        if (fslice[i] <= sslice[j]) {
            start_array[k] = fslice[i];
            i++;
        } else {
            start_array[k] = sslice[j];
            if (k != n)
                count += q - p + 1 - i;
            j++;
        }
    }
    return count;
}

long long  mergeDistr(long start_array[], long p, long n, long long count){
    if (p < n) {
        long q = (n+p)/2;
        count = mergeDistr(start_array, p, q, count);
        count = mergeDistr(start_array, q+1, n, count);
        count = Merge(start_array,p,q,n,count);
    }
    return count;
}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("inversions.in", "r", stdin);
    freopen("inversions.out", "w", stdout);
    int size; cin >> size;
    long start_array[size];
    for (int i = 0 ; i <size; i++){
        cin >> start_array[i];
    }
    long long count = 0;
    count = mergeDistr(start_array, 0, size - 1,count);
    cout << count;
    return 0;
}
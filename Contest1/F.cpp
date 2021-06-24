//Sortland
// Created by Виктор Кумпан on 13.02.2021.
//

#include <iostream>

using namespace  std;

int main() {
    freopen("sortland.in", "r", stdin);
    freopen("sortland.out", "w", stdout);
    int size;
    cin >> size;
    float start_array[size][2];
    float num;
    for (int i = 0; i <size; i ++){
        cin >> num;
        start_array[i][0] = num;
        start_array[i][1] = i+1;
        if (i>0) {
            float val = start_array[i][0];
            int key = start_array[i][1];
            int j = i - 1;
            while ((j > -1) and (start_array[j][0]>val)){
                start_array[j+1][0] = start_array[j][0];
                start_array[j+1][1] = start_array[j][1];
                j-=1;
            }
            start_array[j+1][0] = val;
            start_array[j+1][1] = key;
        }
    }
    cout<< start_array[0][1]<<" " << start_array[size/2][1]<<" "<< start_array[size-1][1];
}

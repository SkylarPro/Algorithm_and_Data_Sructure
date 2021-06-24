//
// Created by Виктор Кумпан on 13.02.2021.
//turtle
#include <iostream>
#include <vector>
using namespace std;

int main() {
    string str;
    int w; int h;
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("turtle.in", "r", stdin);
    freopen("turtle.out", "w", stdout);
    getline(cin,str);
    w = stoi(str.substr(str.find(' '),str.size()-1));
    h = stoi(str.substr(0,str.find(' ')));
    int arr[h][w];
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w;j++){
            if ((i==h-1) and j>0){
                int num;
                cin >> num;
                arr[i][j] = arr[i][j-1] + num;
            } else
                cin >> arr[i][j];
        }
    }
    for (int i = h - 2; i > -1; i--){
        arr[i][0] = arr[i+1][0] + arr[i][0];
    }
    for (int i = h - 2; i > -1; i--){
        for(int j = 1; j < w; j++){
            arr[i][j] = max(arr[i+1][j], arr[i][j-1]) + arr[i][j];
        }
    }
    cout<<arr[0][w-1];
    return 0;
}
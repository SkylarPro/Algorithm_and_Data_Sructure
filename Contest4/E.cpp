// Двоичный поиск
// Created by Виктор Кумпан on 29.03.2021.
// binsearch


#include <iostream>
#include <numeric>
#include <vector>
#include <string>




long long binarysearch(std::vector<long long> &arr, long long num,long long l = -1, long long r = -1){
    if (l == -1){
        l = -1;
    }
    if (r == -1){
        r = arr.size();
    }
    long long m = -1;
    while(r > l + 1){
        m = (l + r) / 2;
        if (arr[m] == num){
            break;
        }
        else if (arr[m] < num)
            l = m;
        else
            r = m;
    }
    return m;
}

void distrib(std::vector<long long> &arr, long long num){
    long long median;
    long long temp;
    long long max_len = arr.size();
    long long min_len = -1;
    std::pair<long, long> ans;

    median = binarysearch(arr, num);
    temp = median;
    if (num!= arr[median]){
        std::cout << -1 <<" " << -1 << "\n";
        return;
    }

    while (true){
        temp = binarysearch(arr,num,temp);
        if (temp == -1){
            ans.second = median;
            break;
        }
        if (temp == max_len - 1){
            if (arr[temp] == num){
                ans.second = temp;
            }
            break;
        }
        if (arr[temp] != num){
            temp--;
            ans.second = temp;
            break;
        }
        if (arr[temp] == num){
            ans.second = temp;
        }
    }
    while (true){
        temp = binarysearch(arr,num,-1,temp);

        if (temp == min_len){
            if (arr[temp] == num){
                ans.first = temp + 1;
            }
            break;
        }

        if (arr[temp] != num){
            temp++;
            ans.first = temp;
            break;
        }
        if (arr[temp] == num){
            ans.first = temp;
        }
    }
    std::cout << ans.first + 1<< " " << ans.second + 1 << "\n";
}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("binsearch.in", "r", stdin);
    freopen("binsearch.out", "w", stdout);
    std::string str;
    std::vector<long long> array;
    std::cin >> str;
    bool checker = false;
    if (stoi(str) == 1){
        checker = true;
    }
    long long num;
    int i = 0;
    while(getline(std::cin, str)){
        i++;
        if (i == 3) continue;
        if (str.empty()) continue;
        if (str.find(' ') == -1 && !checker) continue;
        while (true){
            int space1 = str.find(' ');
            num = stoi(str.substr(0, space1));
            if (i != 4){
                array.push_back(num);
            }else{
                distrib(array,num);
            }
            str = str.substr(space1+1, str.size());
            if (space1 == -1){
                break;
            }
        }
    }

    return 0;
}
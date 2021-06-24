//Соревнования по бегу
// Created by Виктор Кумпан on 14.02.2021.
//race
#include <iostream>
#include <cmath>

using namespace std;

struct Race {
    string country;
    string name;
};

bool checkTown(string fcountry, string scountry) {
    bool check = true;
    long long i = 0;
    long long lenn = min(fcountry.size(),scountry.size());
    int lenn1 = fcountry.size();
    int lenn2 = scountry.size();
    while (check) {
        if (fcountry[i]==scountry[i]) {
            i += 1;
            if (i==lenn){
                if (lenn1 > lenn2)
                    return false;
                return true;
            }

        }
        else if (fcountry[i]<scountry[i])
            return true;
        else if (fcountry[i]>scountry[i])
            return false;
    }

};

void Merge(Race *start_array, int p, int q, int n){
    Race fslice[q - p + 2];
    Race sslice[n - q + 1];
    string maxx(15,'z');
    fslice[q - p + 1].country = maxx;
    sslice[n - q].country = maxx;

    for (int i = 0; i < q - p + 1; i ++)
        fslice[i] = start_array[p+i];

    for (int i = 0; i < n - q;i++)
        sslice[i] = start_array[q+i+1];

    long i = 0;
    long j = 0;
    for (long k = p; k < n+1; k++){
            if (checkTown(fslice[i].country, sslice[j].country)){ // если город стоит первее в алфавите то True, иначе False
                start_array[k] = fslice[i];
                i++;
            }else {
                start_array[k] = sslice[j];
                j++;
            }
        }
}

void mergeDistr(Race *start_array, int p, int n){
    if (p < n) {
        int q = (n+p)/2;
        mergeDistr(start_array, p, q);
        mergeDistr(start_array, q+1, n);
        Merge(start_array,p,q,n);
    }
}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    int  size; cin >> size;
    Race start_array[size];
    for (int i = 0 ; i <size; i++){
        cin >> start_array[i].country >> start_array[i].name;
    }
    mergeDistr(start_array, 0, size - 1);
    string temp = start_array[0].country;
    long long count = 0;
    for(int i =0 ; i<size; i++){
        if (temp == start_array[i].country and count > 0){
            cout <<start_array[i].name<<"\n";
        }else if (count == 0 and temp == start_array[i].country){
            cout <<"=== "<<start_array[i].country<<" ==="<<"\n";
            cout <<start_array[i].name<<"\n";
            count ++;
        }else{
            temp = start_array[i].country;
            count = 1;
            cout <<"=== "<<temp<<" ==="<<"\n";
            cout <<start_array[i].name<<"\n";
        }
    }
    return 0;
}
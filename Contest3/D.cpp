// Приоритетная очередь, реализация через кучу
// Created by Виктор Кумпан on 27.02.2021.
//
//1. Добавить элемент (push x)
//2. Извлечь минимальный элемент (extract - min), если очередь пуста вывести *
//3. Уменьшить элемент decrease-key x y , номер x заменить на номер y
//
// Нужно использовать кучу по убыванию
// priorityqueue

#include <iostream>
#include <vector>

struct Item{
    long val;
    long num;
};

struct Queue {
    std::vector<Item> vec;
    int push(Item num);
    void extract_min();
    int decrease_key(long x, long y);
};

int max_heap(std::vector<Item>& vec, int i){
    int left = 2*i + 1;
    int right = 2*i + 2 ;
    int largest = i;
    if (left<vec.size() && vec[left].val <= vec[i].val) largest = left;
    if (right < vec.size() && vec[right].val <= vec[largest].val) largest = right;
    if (largest != i) {
        std::swap(vec[i],vec[largest]);
        max_heap(vec,largest);
    }
    return 0;
}

int build_heap(std::vector<Item>& vec){
    for (int i = vec.size()/2 - 1; i > -1;i--) max_heap(vec, i);
    return 0;
}

void  Queue::extract_min(){
    if (vec.empty()){
        std::cout<<"*"<<"\n";
    }else{
        std::cout<<vec[0].val<<"\n";
        vec.erase(vec.begin());
        build_heap(vec);
    }
};

int Queue::decrease_key(long x, long y) {
    for(auto & i : vec) if (i.num == x - 1) i.val = y;
    build_heap(vec);
};

int Queue::push(Item num) {
    vec.push_back(num);
    // ставить на нужное место в кучи.
    if (vec.size() > 1) {
        build_heap(vec);
    }
    return 0;
}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("priorityqueue.in", "r", stdin);
    freopen("priorityqueue.out", "w", stdout);
    Queue q;
    std::string str;
    std::string temp;
    long  count = 0;
    while (getline(std::cin,str)){
        if (str.empty()){
            break;
        } else{
            std::string method = str.substr(0,str.find(' '));
            if (method == "push"){
                Item obj;
                obj.num = count;
                obj.val = long(stoi((str.substr(str.find(' ') + 1))));
                q.push(obj);
            }
            if (method == "extract-min")q.extract_min();
            if (method == "decrease-key"){
                str = str.substr(str.find(' ')+1);
                long x = long(stoi(str.substr(0,str.find(' '))));
                long y = long(stoi(str.substr(str.find(' ') + 1)));
                q.decrease_key(x,y);
            }
        }
        ++count;
    }
    return 0;
}
//
// Created by Виктор Кумпан on 19.08.2021.
//
#include <iostream>
#include <string>

struct Node{
    Node* left = nullptr;
    Node* right = nullptr;
    Node* perents = nullptr;
    int key = 0;
    Node(Node*, int key);
};
Node::Node(Node* par,int value){
    key = value;
    left = right = nullptr;
    perents = par;
}

class BinaryTree{
private:
    Node* root = nullptr;
    Node* insert_node(Node*, int);
    void serach_node(Node*, int, bool&);
    void min_after(Node*, int, int&,bool, bool);
    void max_before(Node*, int, int&);
    Node* delete_key(Node*, int, bool&);
public:
    void insert(int);
    void exist(int);
    void next(int);
    void prev(int);
    void del(int);
};

void BinaryTree::insert(int key) {
    root = insert_node(root, key);
}
void BinaryTree::exist(int key) {
    bool flag = false;
    serach_node(root, key,flag);
    flag ? std::cout<<"true"<<"\n" : std::cout<<"false"<<"\n";
}
void BinaryTree::next(int key) {
    int val = std::numeric_limits<int>::max();
    min_after(root, key, val,false,false);
    val == std::numeric_limits<int>::max() ? std::cout<<"none"<<"\n": std::cout<<val<<"\n";
}
void BinaryTree::prev(int key) {
    int val = std::numeric_limits<int>::min();
    max_before(root, key, val);
    val == std::numeric_limits<int>::min() ? std::cout<<"none"<<"\n": std::cout<<val<<"\n";
}
void BinaryTree::del(int key) {
    bool flag = false;
    root = delete_key(root,key, flag);
}

Node* BinaryTree::insert_node(Node* root, int key) {
    if (root == nullptr){
        return new Node(root,key);
    }
    if (root->key < key){
        if (root->right == nullptr){
            root->right = new Node(root,key);
            return root;
        }
        insert_node(root->right,key);
    }
    if (root->key > key){
        if (root->left == nullptr){
            root->left = new Node(root,key);
            return root;
        }
        insert_node(root->left,key);
    }
    return root;
}

void BinaryTree::serach_node(Node* root, int key, bool& flag) {
    if (root->key == key){
        flag = true;
        return;
    }
    if (root->key > key){
        if (root->left != nullptr){
            serach_node(root->left,key, flag);
        }else{
            return;
        }
    }
    if (root->key < key){
        if (root->right != nullptr){
            serach_node(root->right,key,flag);
        }else{
            return;
        }
    }
    return;
}

void BinaryTree::min_after(Node* root,int key, int& val, bool flag, bool del_opt = false) {
    if (root->key > key){
        val = root->key;
        if (root->left == nullptr){
            // custom decide for fast delete items
            if (del_opt){
                delete_key(root,val,flag);
                del_opt = false;
            }
            return;
        }
        flag = false;
        min_after(root->left, key,val,flag, del_opt);
    }
    if (root->key <= key){
        if (root->right== nullptr){
            return;
        }
        flag = true;
        min_after(root->right, key,val,flag, del_opt);
    }
    return;
}

void BinaryTree::max_before(Node* root,int key,int& val) {
    if (root->key < key && root->key > val){
        val = root->key;
        if (root->right == nullptr){
            return;
        }
        max_before(root->right, key,val);
    }
    if (root->key >= key){
        if (root->left== nullptr){
            return;
        }
        max_before(root->left, key,val);
    }
    return;
}

Node* BinaryTree::delete_key(Node* root, int key, bool & flag) {
    // flag it's items for detected road children (left or right for parent)
    if (root->key == key){
        if (root->right == nullptr && root->left == nullptr){
            if (flag == false){
                root->perents->left = nullptr;
            }else{
                root->perents->right = nullptr;
            }
        }else if (root->right != nullptr && root->left == nullptr){
            root->right->perents = root->perents;
            // check on top (base)
            if (root->perents != nullptr){
                if (flag == false){
                    root->perents->left = root->right;
                }else{
                    root->perents->right = root->right;
                }
            }else{
                root = root->right;
            }

        }else if (root->right == nullptr && root->left != nullptr){
            root->left->perents = root->perents;
            if (root->perents != nullptr) {
                if (flag == false){
                    root->perents->left = root->left;
                }else{
                    root->perents->right = root->left;
                }
            }else{
                root = root->left;
            }
        }else{
            int val = std::numeric_limits<int>::max();
            // delete node
            min_after(root->right,key,val,flag,true);
            root->key = val;
        }
        return root;
    }
    if (root->key < key){
        if (root->right == nullptr){
            return root;
        }
        flag = true;
        delete_key(root->right, key,flag);
    }
    if (root->key > key){
        if (root->left == nullptr) {
            return root;
        }
        flag = false;
        delete_key(root->left, key,flag);
    }
    return root;
}


int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("bstsimple.in", "r", stdin);
    freopen("bstsimple.out", "w", stdout);

    std::string str;
    std::string method;
    int value;
    BinaryTree tree;
    while(getline(std::cin, str)){
        method = str.substr(0,str.find(' '));
        value = stoi(str.substr(str.find(" ") + 1));
        if (method == "insert"){
            tree.insert(value);
        }else if(method == "delete"){
            tree.del(value);
        }else if (method == "exists"){
            tree.exist(value);
        }else if (method == "next"){
            tree.next(value);
        }else if (method == "prev"){
            tree.prev(value);
        }
    }
    return 0;
}

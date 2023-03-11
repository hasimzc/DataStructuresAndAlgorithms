
#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};
node * add(node* t, int d){
    if (t == nullptr){
        t = (node*) malloc(sizeof(node));
        t->data = d;
        t->left = nullptr;
        t->right = nullptr;
        return t;
    }
    node * root = t;
    if(t->left != nullptr){
        t=t->left;
    }
    else if(t->right != nullptr){
        t=t->right;
    }
    else{
        cout << "Given node is full" << endl;
        return root;
    }
    t = (node*) malloc(sizeof(node));
    t->data = d;
    t->left = nullptr;
    t->right = nullptr;
    return root;
}

int main() {
    return 0;
}

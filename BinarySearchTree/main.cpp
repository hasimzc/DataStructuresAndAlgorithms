#include <iostream>
#include <stdlib.h>
using namespace  std;
struct bst{
    int data;
    bst* left;
    bst* right;
};
typedef bst node;
node * add(node* t, int d){
    if (t == nullptr){
        t = (node*) malloc(sizeof(node));
        t->data = d;
        t->left = nullptr;
        t->right = nullptr;
        return t;
    }
    node * root = t;
    while(d <= t->data && t->left != nullptr){
            t=t->left;
    }
    while(d > t->data && t->right != nullptr){
            t=t->right;

    }
    if (d <= t->data){
        t->left = (node*) malloc(sizeof(node));
        t->left->data = d;
        t->left->left = nullptr;
        t->left->right = nullptr;
        return root;
    }
    t->right = (node*) malloc(sizeof(node));
    t->right->data = d;
    t->right->left = nullptr;
    t->right->right = nullptr;
    return root;


}
void preorder(node * b){
    if(b == nullptr){
        return;
    }
    cout << b->data << endl;
    preorder(b->left);
    preorder(b->right);
}
void inorder(node* b){
    if(b == nullptr){
        return;
    }
    inorder(b->left);
    cout << b->data << endl;
    inorder(b->right);
}
void postorder(node* b){
    if(b == nullptr){
        return;
    }
    postorder(b->left);
    postorder(b->right);
    cout << b->data << endl;
}
bool search(node* b, int d){
    if(b == nullptr){
        return false;
    }
    if(b->data == d){
        return true;
    }
    if (b->left != nullptr){
        if(search(b->left,d)){
            return true;
        }

    }
    if (b->right != nullptr){
        if(search(b->right,d)){
            return true;
        }
    }
    return false;
}
int max(node* b){
    while (b->right != nullptr){
        b = b->right;
    }
    return b->data;
}
int min(node* b){
    while (b->left != nullptr){
        b = b->left;
    }
    return b->data;
}
node * deletion(node* b, int d){
    if(!search(b,d)){
        cout << "deletion failed because given data is not in the tree. " << endl;
        return b;
    }
    if(b->data == d){
        if(b->left == nullptr && b->right == nullptr){
            return nullptr;
        }
        if(b->left != nullptr){
            int value = max(b->left);
            b->data = value;
            b->left = deletion(b->left,max(b->left));
            return b;
        }
        int value = min(b->right);
        b->data = value;
        b->right = deletion(b->right,min(b->right));
        return b;
    }
    if(d < b->data){
        b->left = deletion(b->left,d);
        return b;
    }
    b->right = deletion(b->right,d);
    return b;

}
void printLevel(node* root, int number, int level){
    if(root == nullptr){

    }
    else if(number == root->data){
        cout << level;
    }
    else{
        if(number < root->data){
            printLevel(root->left,number,++level);
        }
        else{
            printLevel(root->right,number,++level);
        }
    }
}
int main() {
    node * bst = nullptr;
    bst = add(bst,10);
    bst = add(bst,15);
    bst = add(bst,5);
    bst = add(bst,1);
    bst = add(bst,6);
    bst= add(bst,12);
    bst = add(bst,17);
    //cout << search(bst,3) << endl;
    //cout << max(bst) << endl;
    //bst = deletion(bst,15);
    //inorder(bst);
    //cout << search(bst,17);
    printLevel(bst,15,1);
    postorder(bst);
    return 0;
}

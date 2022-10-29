#include <iostream>
#include <stdlib.h>
using namespace std;
struct n{
    int data;
    n* next;
    n* prev;
};
typedef n node;
void print(node* r){
    while (r != NULL){
        cout << r->data << endl;
        r = r->next;
    }
}
node* add(node* r ,int d){
    if(r == NULL){
        r = (node*) malloc(sizeof(node));
        r->data = d;
        r->next = NULL;
        r->prev = NULL;
        return r;
    }
    else{
        node* root = r;
        while (r->next!= NULL){
            r = r->next;
        }
        node * n_r = (node*) malloc(sizeof(node));
        n_r->data = d;
        n_r->next = NULL;
        n_r->prev = r;
        r->next = n_r;
        return root;
    }

}
node * addInorder(node * r, int d){
    if (r == NULL){
        r = (node*) malloc(sizeof(node));
        r->data = d;
        r->next = NULL;
        r->prev = NULL;
        return r;
    }
    else{
        node * n_r = (node*) malloc(sizeof(node));
        n_r->data = d;
        if(d<r->data){
            n_r->next = r;
            n_r->prev = NULL;
            r->prev = n_r;
            return n_r;
        }
        else{
            node * root = r;
            while (r->data < d){
                if(r->next == NULL){
                    n_r->next = NULL;
                    n_r->prev = r;
                    r->next = n_r;
                    return root;
                }
                else if(r->next->data < d){
                    r = r->next;
                }
                else{
                    break;
                }
            }
            n_r->next = r->next;
            n_r->prev = r;
            r->next = n_r;
            return root;
        }
    }
}
bool isValid(node* r,int d){
    while (r->next != NULL){
        if (r->data == d){
            return true;
        }
        r = r->next;
    }
    return r->data == d;
}
node * del(node* r,int d){
    if(isValid(r,d)){
        if(r->data == d){
            r = r->next;
            r->prev = NULL;
            return r;
        }
        else{
            node* root = r;
            while (r->next->data != d){
                r = r->next;
            }
            if(r->next->next == NULL){
                r->next = NULL;
                return root;
            }
            else{
                r->next = r->next->next;
                r->next->prev = r;
                return root;
            }
        }
    }
    else{
        cout << "sayi bulunamadig, icin del metodu calismadi." << endl;
        return r;
    }
}

int main() {
    node * root = NULL;
    root = addInorder(root,10);
    root = addInorder(root,20);
    root = addInorder(root,15);
    root = addInorder(root,0);
    root = addInorder(root,30);
    root = add(root,50);
    root = del(root,0);
    root = del(root,50);
    root = del(root,20);
    print(root);
    return 0;
}

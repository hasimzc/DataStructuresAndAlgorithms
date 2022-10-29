#include <iostream>
#include <stdlib.h>
using namespace std;
struct n{
    int data;
    n * next;
};
typedef n node;
void bastir(node* r){
    node* iter = r;
    cout << r->data << endl;
    r = r->next;
    while(r != iter){
        cout << r->data << endl;
        r = r->next;
    }
}
node* ekle(node* r, int d){
    if (r == NULL){
        r= (node*) malloc(sizeof(node));
        r->data = d;
        r->next = r;
        return r;
    }
    else{
        node* iter = r;
        while(r->next != iter){
            r = r->next;
        }
        r->next = (node*) malloc(sizeof(node));
        r = r->next;
        r->data = d;
        r->next = iter;
        return iter;
    }



}
void insert(node* r,int d,int index){
    int counter =0;
    while (counter != index-1){
        r = r->next;
        counter++;
    }
    node* n_node = (node*) malloc(sizeof(node));
    n_node->data = d;
    n_node->next = r->next;
    r->next = n_node;
}
node* inorder(node*r,int d){
    node* iter = r;
    if (r==NULL){
        r = (node*) malloc(sizeof(node));
        r->data = d;
        r->next = iter;
        return r;
    }
    else if(r->next == iter){
        node* n_r = (node*) malloc(sizeof(node));
        n_r->data = d;
        if(d<r->data){
            n_r->next = r;
            r->next = n_r;
            return n_r;
        }
        else{
            n_r->next = iter;
            r->next = n_r;
            return r;
        }

    }
    else{
        node* n_node = (node*) malloc(sizeof (node));
        n_node->data = d;
        if (r->data > d){
            n_node -> next = r;
            while (r->next->data >= r->data){
                r=r->next;
            }
            r->next = n_node;
            return n_node;
        }
        else{
            while (r->data <= d) {
                if(r->next == iter){
                    break;
                }
                else if(r->next->data <= d){
                    r = r->next;
                }
                else{
                    break;
                }
            }

            if(r->next == iter){
                n_node->next = iter;
                r->next = n_node;
            }
            else{
                n_node->next= r->next;
                r->next= n_node;
            }
            return iter;
        }

    }

}
int main() {
    node* root = (node*)malloc(sizeof(node));
    root = NULL;
    root = ekle(root,0);
    root = ekle(root,5);
    root = ekle(root,60);
    root = inorder(root,55);
    root = inorder(root,-10);
    root = inorder(root,100);
    bastir(root);

    return 0;
}


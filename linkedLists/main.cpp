#include <iostream>
#include <cstdlib>
using namespace std;
struct n{
    int data;
    n * next;
};
typedef n node;
void bastir(node* r){
    if(r == nullptr){
        cout << "the linked list is null." << endl;
    }
    else{
        while(r != nullptr){
            cout << r->data << endl;
            r = r->next;
        }
    }
}
void ekle(node* r, int d){
    while(r->next != nullptr){
        r = r->next;
    }
    r->next = (node*) malloc(sizeof(node));
    r = r->next;
    r->data = d;
    r->next = nullptr;
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
    if (r==nullptr){
        r = (node*) malloc(sizeof(node));
        r->data = d;
        r->next = nullptr;
        return r;
    }
    else if(r->next == nullptr){
        node* n_r = (node*) malloc(sizeof(node));
        n_r->data = d;
        if(d<r->data){
            n_r->next = r;
            return n_r;
        }
        else{
            n_r->next = nullptr;
            r->next = n_r;
            return r;
        }

    }
    else{
        node* root = r;
        node* n_node = (node*) malloc(sizeof (node));
        n_node->data = d;
        if (r->data > d){
            n_node -> next = r;
            return n_node;
        }
        else{
            while (r->data <= d) {
                if(r->next == nullptr){
                    break;
                }
                else if(r->next->data <= d){
                    r = r->next;
                }
                else{
                    break;
                }
            }

            if(r->next == nullptr){
                n_node->next = nullptr;
                r->next = n_node;
            }
            else{
                n_node->data = d;
                n_node->next= r->next;
                r->next= n_node;
            }
            return root;
        }

    }

}
bool isValid(node* r,int d){
    bool isIn= false;
    while (r != nullptr){
        if (r->data == d){
            isIn = true;
            break;
        }
        r = r->next;
    }
    return isIn;
}
node* del(node* r,int d){
    node * temp = r;
    if (isValid(r,d)){
        if (temp->data == d){
            r=r->next;
            free(temp);
            return r;
        }
        else{
            while (r->next->data != d){
                r = r->next;
            }
            node * garbage = r->next;
            r->next = r->next->next;
            free(garbage);
            return temp;
        }
    } else {
        cout << "Delete method didn't work because the value isn't in the linked list. "<<endl;
        return temp;
    }
}
void freeList(node* head){
    if(head == nullptr){

    }
    else if(head->next == nullptr){
        free(head);
    }
    else{
        node * iter = head->next;
        free(head);
        freeList(iter);
    }
}

int main() {
    node* root = (node*)malloc(sizeof(node));
    root = nullptr;
    bastir(root);
    root= inorder(root,-10);
    root = inorder(root, 0);
    root = inorder(root,-15);
    root = inorder(root, 50);
    root = del(root,0);
    root =del(root,0);
    root = del(root,-15);
    ekle(root,100);
    root = del(root,100);
    root = del(root,999);
    ekle(root,100);
    bastir(root);
    freeList(root);
    return 0;
}

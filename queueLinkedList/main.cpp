#include <stdlib.h>
#include <iostream>
using namespace std;

struct queue{
    int data;
    queue * next;
};
typedef queue node;
bool isThereAny = true;
node * dequeue(node* q){
    if(q == nullptr){
        return q;
    }
    else{
        return q->next;
    }
}
node* enqueue(node* q,int d){
    if(q == nullptr){
        q = (node*) malloc(sizeof(node));
        q->data = d;
        q->next = nullptr;
        return q;
    }
    else{
        node* root = q;
        while (q->next!= nullptr){
            q = q->next;
        }
        node * new_node = (node*) malloc(sizeof(node));
        new_node->data = d;
        new_node->next = nullptr;
        q->next = new_node;
        return root;
    }
}
void print(node*q){
    if (q== nullptr){
    }
    else{
        while (q != nullptr){
            cout << q->data << endl;
            q = q->next;
        }
    }
}
int main() {
    node * queue = nullptr;
    queue = enqueue(queue,0);
    queue = enqueue(queue,10);
    print(queue);
    queue = dequeue(queue);
    queue = dequeue(queue);
    print(queue);
    queue = enqueue(queue,5);
    print(queue);
    queue = dequeue(queue);
    queue = dequeue(queue);
    print(queue);
    return 0;
}

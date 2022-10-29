#include <iostream>
#include <stdlib.h>
using namespace std;
struct stack{
    int data;
    stack* next;
};
typedef stack node;
node* pop(node*s){
    if(s == nullptr){
        cout << "stack is empty! " << endl;
        return s;
    }
    else if(s->next == nullptr){
        int value = s->data;
        s= nullptr;
        cout << value << endl;
        return s;
    }
    node* root = s;
    while (s->next->next != nullptr){
        s = s->next;
    }
    node* temp = s->next;
    int value = temp->data;
    free(temp);
    s->next = nullptr;
    cout << value << endl;
    return root;
}
node* push(node* s,int d){
    if(s == nullptr){
        s = (node*) malloc(sizeof (node));
        s->data = d;
        s->next = nullptr;
        return s;
    }
    else{
        node* root = s;
        while (s->next != nullptr){
            s = s->next;
        }
        node * new_stack = (node*) malloc(sizeof(node));
        new_stack->data = d;
        new_stack->next = nullptr;
        s->next = new_stack;
        return root;
    }
}
void print(node* s){
    while (s != nullptr){
        cout << s->data << endl;
        s = s->next;
    }
}
int main() {
    node* stack = nullptr;
    stack = push(stack,10);
    stack = push(stack,15);
    stack = push(stack,20);
    print(stack);
    stack = pop(stack);
    stack = push(stack,25);
    print(stack);
    stack = pop(stack);
    stack = pop(stack);
    print(stack);
    stack = pop(stack);
    stack = pop(stack);
    print(stack);
    return 0;
}

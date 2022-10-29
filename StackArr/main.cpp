#include <iostream>
using namespace std;
int stack[100];
int sizeOfStack = 100;
int top=0;
void push(int i){
    if(top >= sizeOfStack){
        cout << "stack doldu." << endl;
    }
    stack[top++] = i;
}
int pop(){
    if(top==0){
        cout << "stack bos." << endl;
        return -1;
    }
    return stack[--top];
}
void print(int s[]){
    for (int i =0 ; i<top;i++){
        cout << s[i] << endl;
    }
}
int main() {
    push(5);
    push(10);
    print(stack);
    cout << pop() << endl;
    print(stack);
    push(15);
    push(20);
    print(stack);
    return 0;
}

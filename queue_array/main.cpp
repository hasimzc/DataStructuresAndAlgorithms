#include <iostream>
using namespace std;
int queue[100];
int sizeOfQueue = 100;
int head= 0;
int tail =0;
void toparla(int q[]){
    if (head != 0){
        for(int i= 0;i < tail-head;i++){
            q[i] = q[i+head];
    }
        tail -= head;
        head = 0;
    }

}
void enqueue(int q[], int d){
    if (tail == sizeOfQueue-1){
        cout << "queue is full " << endl;
    }
    else{
        q[tail++] = d;
    }
    if(tail == sizeOfQueue-2){
        toparla(q);
    }

}
int dequeue(int q[]){
    if (head==tail){
        cout << "queue is empty." << endl;
    }
    return q[head++];
}
void print(int q[]){
    for (int i =head ; i<tail; i++){
        cout << queue[i] << endl;
    }
}
void a(){
    for (int i =0;i <5;i++){
        enqueue(queue,i*10);
    }
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
}
int main() {
    for(int i=0; i<41;i++){
        a();
    }
    print(queue);
    return 0;
}

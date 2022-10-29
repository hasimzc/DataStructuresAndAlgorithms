#include <iostream>
using namespace std;
struct hash_table{
    int key;
    int value;

};
typedef hash_table h;
h a[13];
int my_hash(int x){
    return x%13;
}
void put(h data){
    if (a[my_hash(data.key)].key == 0){
        a[my_hash(data.key)].value = data.value;
        a[my_hash(data.key)].key = data.key;
    }
    else{
            int indis = my_hash(data.key);
            int cycle = 0;
            while(a[indis].key != 0 && a[indis].key != data.key){
                indis++;
                if(indis >=27){
                    if(cycle >=1){
                        cout << "hashe table dolu." << endl;
                        break;
                    }
                    indis %= 27;
                    cycle++;
                }
            }
            a[indis].value = data.value;
            a[indis].key = data.key;
    }
}
int get(int key){
    if (a[my_hash(key)].key== 0){
        cout << "the key "<< key <<  " is not in the hast table." << endl;
        return 0;
    }
    if (a[my_hash(key)].key== key){
        return a[my_hash(key)].value;
    }
    int indis = my_hash(key);
    int cycle = 0;
    while(a[indis].key != key){
        indis++;
        if(indis >=13){
            if(cycle >=1){
                cout << "the key " << key << " is not in the hashe table" << endl;
                return 0;
            }
            cycle++;
        }
    }
    return a[indis].value;
}
void print(){
    for (int i=0; i<13;i++){
        cout << a[i].value << endl;
    }
}
int main() {
    h data;
    data.key =15;
    data.value = 4654654;
    put(data);
    h data1;
    data1.key =9;
    data1.value = 15153;
    put(data1);
    h data2;
    data2.key =28;
    data2.value = 18;
    put(data2);
    h data3;
    data3.key = 28;
    data3.value = 181818;
    put(data3);
    cout << get(data.key)<< endl;
    cout << get(data1.key) << endl;
    cout << get(data2.key) << endl;
    print();
    cout << get(2) << endl;
    return 0;
}

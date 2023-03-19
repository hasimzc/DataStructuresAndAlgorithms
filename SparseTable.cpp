//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

// range minimum query problem with using sparse table

int main() {
    int n,number,q,l,r;
    cin >> n;
    int log = log2(n);
    vector<vector<int>> numbers(n,vector<int>(log+1));
    for(int i=0;i<n;i++) {
        cin >> number;
        numbers[i][0] = number;
    }
    for(int j =1;j<log+1;j++){
        for(int i =0; i + (pow(2, j)) -1 < n ;i++){
            numbers[i][j] = min(numbers[i][j-1],numbers[i+pow(2, j-1)][j-1]);
        }
    }
    cin >> q;
    while(q--){
        cin >> l >> r;
        int k = log2(r-l+1);
        cout << min(numbers[l][k],numbers[r-pow(2, k)+1][k]) << endl;
    }
    return 0;
}

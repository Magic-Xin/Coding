#include<bits/stdc++.h>
using namespace std;

int n;
int c[5][5] = {0, -1, 1, 1, -1, 1, 0, -1, 1, -1, -1, 1, 0, -1, 1, -1, -1, 1, 0, 1, 1, 1, -1, -1, 0};

int main(){
    cin >> n;
    int a, b, r, ar = 0, br = 0, k = 0;
    cin >> a >> b;
    int aa[a], bb[b];
    for(int i = 0 ; i < a ; i++){
        cin >> aa[i];
    }
    for(int i = 0 ; i < b ; i++){
        cin >> bb[i];
    }
    while(k < n){
        r = c[aa[k%a]][bb[k%b]];
        if(r == -1){
            br++;
        }
        else if(r == 1){
            ar++;
        }
        k++;
    }
    cout << ar << " " << br;
    return 0;
}
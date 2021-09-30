#include<bits/stdc++.h>
using namespace std;

int main(){
    string j, k;
    getline(cin, j);
    getline(cin, k);
    char a[6], c[6];
    int b[6], d[6];
    int m = 1, n = 1;
    strcpy(a, j.data());
    strcpy(c, k.data());

    for(int i=0;i<6;i++){
        b[i] = a[i] - 64;
    }
    for(int i=0;i<6;i++){
        d[i] = c[i] - 64;
    }

    for(int i=0;i<6;i++){
        if(b[i] >= 1 && b[i] <= 64){
            m *= b[i];
        }
        else{
            break;
        }
    }
    for(int i=0;i<6;i++){
        if(d[i] >= 1 && d[i] <= 64){
            n *= d[i];
        }
        else{
            break;
        }
    }
    m %= 47;
    n %= 47;
    if(m == n){
        cout<< "GO" <<endl;
    }
    else{
        cout<< "STAY" <<endl;
    }
    return 0;
}
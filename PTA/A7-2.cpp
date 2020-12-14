#include<bits/stdc++.h>
using namespace std;

int zero(int a){
    int n = 0;
    while(a >= 5){
        a = (a - (a % 5)) / 5;
        n += a;
    }
    return n;
}

int main(){
    int n, temp;
    cin >> n;
    int a;
    for(int i = 0 ; i < n ; i++){
        cin >> a;
        cout << zero(a) << endl;
    }
    return 0;
}
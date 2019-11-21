#include<bits/stdc++.h>
using namespace std;

int n, l, r, m = 0, i = 1;

int main(){
    cin >> n;
    if(n == 1){
        cout << "1/1" << endl;
        return 0;
    }
    while(n >= i){
        n -= i;
        i++;
    }
    if(n == 0){
        i--;
        if(i % 2 == 0){
            l = i;
            r = 1;
        }
        else{
            l = 1;
            r = i;
        }
    }
    else{
        n--;
        if(i % 2 == 0){
            l = 1 + n;
            r = i - n;
        }
        else{
            l = i - n;
            r = 1 + n;
        }
    }
    cout << l << "/" << r << endl;
    return 0;
}
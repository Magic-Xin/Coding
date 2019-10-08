#include<bits/stdc++.h>
using namespace std;

int n, k = 0, s;
int i, j;
int a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int b[2000] = {6};

void compare(){
    for(i = 0 ; i < 1000 ; i++){
        for(j = 0 ; j < 1000 ; j++){
            if(b[i] + b[j] + b[i+j] == n){
                k++;
            }
        }
    }
    return;
}

void sum(){
    for(i = 1 ; i < 2000 ; i++){
        s = i;
        while(s > 0){
            b[i] += a[s % 10];
            s /= 10;
        }
    }
    compare();
    return;
}

int main(){
    cin >> n;
    n -= 4;
    sum();
    cout << k;
    return 0;
}
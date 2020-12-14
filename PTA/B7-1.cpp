#include<bits/stdc++.h>
using namespace std;

int n, m = 1;

void factorial(int a){
    int temp = 1;
    for(int i = 2 ; i <= a ; i++){
        temp *= i;
    }
    m += temp;
    if(a == n){
        return;
    }
    else{
        factorial(a+1);
    }
}

int main(){
    cin >> n;
    factorial(2);
    cout << "m=" << m;
    return 0;
}
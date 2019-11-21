#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[1001];

int run(int){
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= i / 2 ; j++){
            a[i] += a[j]; 
        }
        a[i]++; 
    }
    return a[n];
}

int main(){
    cin >> n;
    m = run(n);
    cout << m;
    return 0;
}
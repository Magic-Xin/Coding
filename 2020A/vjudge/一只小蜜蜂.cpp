#include<bits/stdc++.h>
using namespace std;

unsigned long long m[51] = {0, 1, 2};
int a, b, k;

void step(){
    for(int i = 3 ; i < 51 ; i++){
        m[i] = m[i-1] + m[i-2];
    }
    return;
}

int main(){
    step();
    int n;
    cin >> n;
    unsigned long long so[n];
    for(int i = 0 ; i < n ; i++){
        cin >> a >> b;
        k = b - a;
        so[i] = m[k];
    }
    for(int i = 0 ; i < n ; i++){
        cout << so[i] << endl;
    }
    return 0;
}
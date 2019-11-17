#include<bits/stdc++.h>
using namespace std;

char a, b, c;
int n;

void out(char a, char b, char c, int k){
    if(k == 1){
        cout << k << ":" << a << "->" << c << endl; 
    }
    out(a, c, b, k - 1);
    cout << k << ":" << a << "->" << c << endl;
    out(b, a, c, k - 1);
    return;
}

int main(){
    cin >> n >> a >> b >> c;
    out(a, b, c, n);
    return 0;
}
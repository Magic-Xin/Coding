#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    float a, b;
    cin >> a >> b >> n;
    if(b == 0){
        cout << "data input error!";
    }
    else{
        cout << setprecision(n-2) << a / b;
    }
    return 0;
}
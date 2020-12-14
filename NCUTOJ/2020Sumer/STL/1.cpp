#include<bits/stdc++.h>
using namespace std;

bool can(int a, int b, int t){
    if(a + b < t){
        return false;
    }
    else{
        if(a == 0 || b == 0){
            return t == 0 || a + b == t;
        }
        else{
            return t % __gcd(a, b) == 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, t, n;
    cin >> n;
    while (n--)
    {
        cin >> a >> b >> t;
        if(can(a, b, t)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
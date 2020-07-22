#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int a[n];
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    for(int i = 0 ; i < n ; i++){
        if(a[i] % 2 == 1){
            cout << "1" << endl;
        }else{
            cout << (a[i]%4)/2+a[i]/4 << " " << a[i]/2 << endl;
        }
    }
    return 0;
}
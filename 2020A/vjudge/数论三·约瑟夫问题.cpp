#include<bits/stdc++.h>
using namespace std;

int jos(int n, int k){
    if(n == 1){
        return 0;
    }
    int ret;
    if(n < k){
        ret = 0;
        for(int i = 2 ; i <= n ; i++){
            ret = (ret + k) % i;
        }
        return ret;
    }
    ret = jos(n - n / k, k);
    if(ret < n % k){
        ret = ret - n % k + n;
    }
    else{
        ret = ret - n % k + (ret - n % k) / (k - 1); 
    }
    return ret;
}

int main(){
    int n, k, m;
    cin >> m;
    int a[m];
    for(int i = 0 ; i < m ; i++){
        cin >> n >> k;
        a[i] = jos(n, k);
    }
    for(int i = 0 ; i < m ; i++){
        cout << a[i] << endl;
    }
}
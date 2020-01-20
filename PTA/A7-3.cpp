#include<bits/stdc++.h>
using namespace std;

int n, temp = 0;
int a[100][100], b[100][100] = {0};

int dfs(int l, int r){
    if(b[l][r] != 0){
        return b[l][r];
    }
    if(l > n || r > n){
        return 0;
    }
    else{
        return b[l][r] = max(dfs(l+1, r), dfs(l+1, r+1)) + a[l][r];
    }
}

int main(){
    int m;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j <= i ; j++){
            cin >> a[i][j];
        }
    }
    m = dfs(0, 0);
    cout << m;
    return 0;
}
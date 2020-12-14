#include<bits/stdc++.h>
using namespace std;

int n, ans;
int check[8][8];

void setmate(){
    int k;
    for(int i = 0 ; i < 8 ; i++){
        for(int j = 0 ; j < 8 ; j++){
            if(check[i][j]){
                continue;
            }
            }
        }
    }
}

void dfs(int k){
    if(k < n){
        dfs(k+1);
    }
    setmate();
    return;
}

int main(){
    cin >> n;
    dfs(1);
}
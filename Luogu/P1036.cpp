#include<bits/stdc++.h>
using namespace std;

int sum, n, k, temp;
int a[20];
int p = 0;

void prime(){
    if(sum == 1){
        return;
    }
    else{
        int i;
        temp = sqrt(sum) + 1;
        for(i = 2 ; i < temp ; i++){
            if(sum % i == 0){
                break;
            }
        }
        if(i == temp){
            p++;
        }
        return;
    }
}

void dfs(int s, int d){
    if(s == k){
        prime();
        return;
    }
    for(int i = d ; i < n ; i++){
        sum += a[i];
        dfs(s+1, i+1);
        sum -= a[i];
    }
    return;
}



int main(){
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    dfs(0, 0);
    cout << p;
    return 0;
}
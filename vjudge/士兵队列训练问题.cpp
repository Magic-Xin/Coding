#include<bits/stdc++.h>
using namespace std;

void res(int m){
    vector<int> que;
    for(int i = 1 ; i <= m ; i++){
        que.push_back(i);
    }
    pos_1:
    if(que.size() <= 3){
        for(int i = 0 ; i < 2 ; i++){
            cout << que[i] << " ";
        }
        cout << que[2] << endl;
        return;
    }
    pos_2:
    for(int i = 0 ; i < que.size() ; i++){
        if((i + 1) % 2 == 0){
            que.erase(que.begin() + i);
        }
    }
    if(que.size() <= 3){
        goto pos_1;
    }
    for(int i = 0 ; i < que.size() ; i++){
        if((i + 1) % 3 == 0){
            que.erase(que.begin() + i);
        }
    }
    if(que.size() <= 3){
        goto pos_1;
    }
    else{
        goto pos_2;
    }
}

int main(){
    int n, m;
    cin >> n;
    int a[n];
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    for(int i = 0 ; i < n ; i++){
        res(a[i]);
    }
    return 0;
}
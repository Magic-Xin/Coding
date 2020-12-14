#include<bits/stdc++.h>
using namespace std;

queue<pair<int, int>> a;
int puz[5][5];
int step[5][5] = {0};

void check(int n, int k){
    if(n - 1 > 0 && puz[n-1][k] == 0){
        step[n-1][k]++;
        a.push(make_pair(n-1, k));
    }
    if(k - 1 > 0 && puz[n][k-1] == 0){
        step[n][k-1]++;
        a.push(make_pair(n, k-1));
    }
    if(puz[n+1][k] == 0){
        step[n+1][k]++;
        a.push(make_pair(n+1, k));
    }
    if(puz[n][k+1] == 0){
        step[n][k+1]++;
        a.push(make_pair(n, k+1));
    }
    return;
}

void bfs(){
    int n = a.front().first;
    int k = a.front().second;
    check(n, k);
    a.pop();
    if(a.empty()){
        return;
    }
    bfs();
}

int main(){
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            cin >> puz[i][j];
        }
    }
    a.push(make_pair(0, 0));
    bfs();
    
}
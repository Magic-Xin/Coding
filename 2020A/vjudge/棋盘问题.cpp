#include<bits/stdc++.h>
using namespace std;

int n, k, t;
int p[8][8];
char q[8][8];

void re_check(int a, int b){
    for(int i = 0 ; i < n ; i++){
        if(p[a][i] != 0 && i != b){
            p[a][i]--;
        }
        if(p[i][b] != 0 && i != a){
            p[i][b]--;
        }
    }
    return;
}

void set_check(int a, int b){
    for(int i = 0 ; i < n ; i++){
        if(p[a][i] != 0 && i != b){
            p[a][i]++;
        }
        if(p[i][b] != 0 && i != a){
            p[i][b]++;
        }
    }
    return;
}

void place(int m){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(p[i][j] != 0){
                p[i][j]++;
                set_check(i, j);
                if(m < k){
                    place(m+1);
                    return;
                }
                t++;
                re_check(i, j);
            }
        }
    }
    return;
}

int main(){
    vector<int> ans;
    cin >> n >> k;
    while(n != -1 && k != -1){
        char temp;
        t = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                cin >> temp;
                if(temp == '.'){
                    p[i][j] = 0;
                }
                if(temp == '#'){
                    p[i][j] = 1;
                }
               //cout << p[i][j] << endl;
            }
        }
        place(1);
        ans.push_back(t);
        cin >> n >> k;
    }
    for(auto i = ans.begin() ; i != ans.end() ; i++){
        cout << *i << endl;
    }
    return 0;
}
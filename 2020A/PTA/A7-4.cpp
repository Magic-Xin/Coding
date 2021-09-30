#include<bits/stdc++.h>
using namespace std;

int n;

struct Leafnode {
    int lch = 0;
    int rch = 0;
} a[1000];

void preorder(int pos){
    if(pos == 0){
        return;
    }
    cout << pos << " ";
    preorder(a[pos].lch);
    preorder(a[pos].rch);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int lt, rt;
    cin >> n;  
    for(int i = 1 ; i <= n ; i++){
        cin >> lt >> rt;
        a[i].lch = lt;
        a[i].rch = rt;
    }
    preorder(1);
    return 0;
}

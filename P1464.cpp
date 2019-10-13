#include<bits/stdc++.h>
using namespace std;

long long int a, b, c, n;
long long int ww[21][21][21] = {0};
vector<long long int> aa, bb, cc;

int w(int a, int b, int c){
    if(a <= 0 || b <= 0 || c <= 0){
        return 1;
    }
    else if(a > 20 || b > 20 || c > 20){
        return w(20, 20, 20);
    }
    else if(ww[a][b][c] != 0){
        return ww[a][b][c];
    }
    else if(a < b && b < c){
        ww[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    }
    else{
        ww[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    }
    return ww[a][b][c];
}

int main(){
    pos_1:
    cin >> a >> b >> c;
    if(a == -1 && b == -1 && c == -1){
        goto pos_2;
    }
    else{
        aa.push_back(a);
        bb.push_back(b);
        cc.push_back(c);
        goto pos_1;
    }
    pos_2:
    for(int i = 0 ; i < aa.size() ; i++){
        n = w(aa[i], bb[i], cc[i]);
        cout << "w(" << aa[i] << ", " << bb[i] << ", " << cc[i] << ") = " << n << endl;
    }
    return 0;
}
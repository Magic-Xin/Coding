#include<bits/stdc++.h>
using namespace std;

int n, a, b, x, y, ax, by, k = 0;

int main(){
    cin >> n;
    int aa[n], bb[n], xx[n], yy[n];
    for(int i = 0 ; i < n ; ++i){
        cin >> a >> b >> x >> y;
        aa[i] = a;
        bb[i] = b;
        xx[i] = a + x;
        yy[i] = b + y;
    }
    cin >> ax >> by;
    for(int i = 0 ; i < n ; ++i){
        if(aa[i] <= ax && xx[i] >= ax && bb[i] <= by && yy[i] >= by){
            k = i + 1;
        }
    }
    if(k == 0){
        cout << "-1" << endl;
    }
    else{
        cout << k << endl;
    }
    return 0;
}
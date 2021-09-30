#include<bits/stdc++.h>
using namespace std;

int m, n, k, l, d;
int x[1005], y[1005], xx[1005], yy[1005];

void seatseat(){
    for(int i = 1 ; i <= d ; ++i){
        int xi, yi, xxi, yyi;
        cin >> xi >> yi >> xxi >> yyi;
        if(xi == xxi){
            ++x[min(yi, yyi)];
        }
        else{
            ++y[min(xi, xxi)]; 
        }
    }
    for(int i = 0 ; i <= k ; ++i){
        int max = -1, p = 0;
        for(int j = 1 ; j <= m ; ++j){
            if(x[j] > max){
                max = x[j];
                p = j;
            }
        }
        x[p] = 0;
        ++xx[p];
    }
    for(int i = 0 ; i <= k ; ++i){
        int max = -1, p = 0;
        for(int j = 1 ; j <= n ; ++j){
            if(y[j] > max){
                max = y[j];
                p = j;
            }
        }
        y[p] = 0;
        ++yy[p];
    }
    return;
}

int main(){
    cin >> m >> n >> k >> l >> d;
    seatseat();
    for(int i = 0 ; i < 1005 ; ++i){
        if(yy[i]){
            cout << i << " ";
        }
    }
    cout << endl;
    for(int i = 0 ; i < 1005 ; ++i){
        if(xx[i]){
            cout << i << " ";
        }
    }
    return 0;
}
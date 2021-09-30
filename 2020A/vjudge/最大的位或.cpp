#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int n;
int a[64], b[64];
ull x, y;
vector<ull> sum;

void b2d(int j){
    ull z = 0;
    int k = 0;
    for(int i = j - 1 ; i >= 0 ; i--){
        if(a[i]==b[i])
            {
                if(b[i])
                {
                    z += (ull)pow(2,i);
                }
            }
            else
            {
                z += (ull)pow(2,i+1) - 1;
                break;
            }
    }
    sum.push_back(z);
    return;
}

void d2b(){
    int i = 0, j = 0;
    while(x){
        a[i] = x % 2;
        x /= 2;
        i++;
    }
    while(y){
        b[j] = y % 2;
        y /= 2;
        j++;
    }
    b2d(j);
    return;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        cin >> x >> y;
        d2b();
    }
    for(auto i = sum.begin() ; i != sum.end() ; ++i){
        cout << *i << endl;
    }
    return 0;
}
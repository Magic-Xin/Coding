#include <bits/stdc++.h>
#define read(n) scanf("%lld", &n)
#define readd(n, m) scanf("%lld%lld", &n, &m)
#define print(n) printf("%lld ", n)
#define mst(n, m) memset(n, m, sizeof n)
#define ll long long
using namespace std;

int main(){
    ll n, m, l, r;
    readd(n, m);
    ll* a = new ll[10000001];
    ll* b = new ll[10000001];
    mst(a, 0);
    mst(b, 0);
    for(ll i = 1 ; i <= n ; i++){
        read(a[i]);
    }
    while(m--){
        readd(l,r);
        b[l]++;
        b[r+1]--;
    }
    for(ll i = 1 ; i <= n ; i++){
        b[i] += b[i-1];
        print(b[i]+a[i]);
    }
    delete []a;
    delete []b;
    return 0;
}
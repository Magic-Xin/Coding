#include<bits/stdc++.h>

#define int long long
using namespace std;

int n, k;
 
bool check(int a[], int mid) {
    int s = 0;
    for (int i = n  / 2; i < n; i++) {
        if (a[i] < mid) {
            s += mid - a[i];
            if(s > k){
                return false;
            }
        }
    }
    return true;
}
 
signed main(){
    while(cin >> n >> k){
        int a[n];
        for(int i =0; i < n; i++){
            cin >> a[i];
        }
        sort(a, a + n);
        int l = 0, r = 1e11, ans;
        while(l <= r){
            int mid = (l + r) / 2;
            if(check(a, mid)){
                ans = mid;
                l = mid + 1;
            } 
            else{
                r = mid - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
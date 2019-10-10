#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    int p, q, r, n;
    int d, e, f, g, h, i, j, k, l;
    n = 0;
    cin >> p >> q >> r;
    for(a=100;a<1000;a++){
        b = q * a / p;
        c = r * a / p;
        d = a/100;
        e = (a/10)%10;
        f = a%10;
        g = b/100;
        h = (b/10)%10;
        i = b%10;
        j = c/100;
        k = (c/10)%10;
        l = c%10;
        if (d!=0 && e!=0 && f!=0 && g!=0 && h!=0 && i!=0 && j!=0 && k!=0 && l!=0 && d!=e && d!=f && d!=g && d!=h && d!=i && d!=j && d!=k && d!=l && e!=f && e!=g && e!=h && e!=i && e!=j && e!=k && e!=l && f!=g && f!=h && f!=i && f!=j && f!=k && f!=l && g!=h && g!=i && g!=j && g!=k && g!=l && h!=i && h!=j && h!=k && h!=l && i!=j && i!=k && i!=l && j!=k && j!=l && k!=l && b<1000 && c<1000){
        cout << a << " " << b << " " << c << endl;
        n++;
        }
    }
    if(n == 0){
        cout << "No!!!" << endl;
    }
    return 0;
}
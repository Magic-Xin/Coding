#include <bits/stdc++.h>
using namespace std;

int ct(int t1, int t2)
{
    return t2 == 0 ? t1 : ct(t2, t1 % t2);
}

int main()
{
    int n, t1, t2, res = 0;
    cin >> n;
    int a[n + 1], b[n + 1];
    cin >> a[0] >> b[0];
    for (int i = 1; i < n + 1; i++)
    {
        cin >> a[i] >> b[i];
        t1 = abs(a[i] - a[i - 1]);
        t2 = abs(b[i] - b[i - 1]);
        res += ct(t1, t2);
    }
    cout << ++res;
    return 0;
}
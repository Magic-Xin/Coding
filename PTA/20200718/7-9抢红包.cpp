#include <bits/stdc++.h>
using namespace std;

struct P
{
    int i;
    int n;
    int m;
};

bool cmp(const P &a, const P &b)
{
    if (a.m != b.m)
    {
        return a.m > b.m;
    }
    if (a.n != b.n)
    {
        return a.n > b.n;
    }
    return a.i < b.i;
}

int main()
{
    int n, k, q, p;
    cin >> n;
    P a[n + 1];
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++)
    {
        a[i].i = i;
        cin >> k;
        while (k--)
        {
            cin >> q >> p;
            a[q].n++;
            a[q].m += p;
            a[i].m -= p;
        }
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        cout << a[i].i << " ";
        printf("%.2lf\n", (a[i].m * 1.0) / 100);
    }
    return 0;
}
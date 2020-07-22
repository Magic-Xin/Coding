#include <bits/stdc++.h>
#define N 1000010
using namespace std;

int n;
char s[N];
int a[N], res[N];

bool cmp(int x, int y)
{
    int flag = 0;
    if (x > y)
    {
        swap(x, y);
        flag = 1;
    }
    if (a[x] >= y)
    {
        return 1 ^ flag;
    }
    else
    {
        return (s[a[x]] > s[a[x] + 1]) ^ flag;
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    cin >> s + 1;
    a[n] = n;
    for (int i = n - 1; i > 0; i--)
    {
        if (s[i] != s[i + 1])
        {
            a[i] = i;
        }
        else
        {
            a[i] = a[i + 1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        res[i] = i;
    }
    sort(res + 1, res + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}
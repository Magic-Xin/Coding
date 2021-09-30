#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < m; i++)
    {
        if (binary_search(a, a + n, b[i]))
        {
            cout << n - (lower_bound(a, a + n, b[i]) - a) << endl;
        }
        else
        {
            cout << "meiyou" << endl;
        }
    }
    return 0;
}
#include <bits/stdc++.h>
#define INF 999999
#define DEBUG
using namespace std;

int main()
{
#ifdef DEBUG
    int a[4][4] = {{0, 2, 6, 4}, {INF, 0, 3, INF}, {7, INF, 0, 1}, {5, INF, 12, 0}};
    int n = 4;
#else
    int m, n, t1, t2, t3;
    cin >> m >> n;
    int a[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                a[i][j] = 0;
            }
            else
            {
                a[i][j] = INF;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        cin >> t1 >> t2 >> t3;
        a[t1][t2] = t3;
    }
#endif
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (a[j][k] > a[j][i] + a[i][k])
                {
                    a[j][k] = a[j][i] + a[i][k];
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
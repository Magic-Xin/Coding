#include <bits/stdc++.h>
using namespace std;

int gx[101][101];
int n, m, k;

int find(int c, int d)
{
    for (int i = 1; i <= n; i++)
    {
        if (gx[c][i] != 0 && gx[d][i] != 0)
            return 1;
    }
    return 0;
}
int main()
{
    cin >> n >> m >> k;
    memset(gx, 0, sizeof(gx));
    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        gx[a][b] = c;
        gx[b][a] = c;
    }
    for (int i = 0; i < k; i++)
    {
        cin >> a >> b;
        if (gx[a][b] == 1)
        {
            cout << "No problem" << endl;
        }
        else if (gx[a][b] == 0)
        {
            cout << "OK" << endl;
        }
        else if (gx[a][b] == -1 && find(a, b) == 1)
        {
            cout << "OK but..." << endl;
        }
        else
        {
            cout << "No way" << endl;
        }
    }
    return 0;
}
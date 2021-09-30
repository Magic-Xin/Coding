#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a[65536] = {0};
    char status[6];
    while (gets(status))
    {
        if (status[0] == 'q')
        {
            int n = status[2] - '0';
            cout << a[n];
        }
        if (status[0] == 'a')
        {
            int n = status[2] - '0', m = status[4] - '0';
            for (int i = n; i <= m; i++)
            {
                a[i] = 1;
            }
        }
        if (status[0] == 'b')
        {
            int n = status[2] - '0', m = status[4] - '0';
            for (int i = n; i <= m; i++)
            {
                a[i] = 0;
            }
        }
        if (status[0] == 'c')
        {
            int n = status[2] - '0', m = status[4] - '0';
            for (int i = n; i <= m; i++)
            {
                if (a[i])
                {
                    a[i] = 0;
                }
                else
                {
                    a[i] = 1;
                }
            }
        }
    }
    return 0;
}
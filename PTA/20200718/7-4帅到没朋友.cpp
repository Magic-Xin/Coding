#include <bits/stdc++.h>
using namespace std;

int main()
{
    int pyq[100000];
    int n, k, m;
    vector<int> out;
    cin >> n;
    memset(pyq, 0, sizeof(pyq));
    while (n--)
    {
        cin >> k;
        if (k == 1)
        {
            cin >> m;
            continue;
        }
        while (k--)
        {
            cin >> m;
            pyq[m]++;
        }
    }
    cin >> n;
    k = 0;
    while (n--)
    {
        cin >> m;
        if (pyq[m] == 0)
        {
            out.push_back(m);
            k++;
            pyq[m]++;
        }
    }
    if (k == 0)
    {
        cout << "No one is handsome";
    }
    else
    {
        for (int i = 0; i < out.size() - 1; i++)
        {
            printf("%05d ", out[i]);
        }
        printf("%05d", out[out.size() - 1]);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[1001] = {0};
    int temp;
    while (cin >> temp)
    {
        a[temp]++;
    }
    for (int i = 0; i < 1001; i++)
    {
        for (int j = 1; j <= a[i]; j++)
        {
            cout << i << " ";
        }
    }
    return 0;
}
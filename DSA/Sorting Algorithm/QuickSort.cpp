#include <bits/stdc++.h>
using namespace std;

void sort(int a[], int l, int r)
{
    if (l > r)
    {
        return;
    }
    int i, j, t, temp;
    temp = a[l];
    i = l;
    j = r;
    while (i != j)
    {
        while (a[j] >= temp && j > i)
        {
            j--;
        }
        while (a[i] <= temp && i < j)
        {
            i++;
        }
        if (i < j)
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    a[l] = a[i];
    a[i] = temp;
    sort(a, l, i - 1);
    sort(a, i + 1, r);
    return;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
#include <bits/stdc++.h>
#define DEBUG
using namespace std;

void sort(int a[], int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    return;
}

int main()
{
#ifdef DEBUG
    int n = 5;
    int a[n] = {4, 3, 1, 5, 2};
#else
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
#endif
    sort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
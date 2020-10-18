#include <bits/stdc++.h>
using namespace std;

void sort(int a[100], int len)
{
    int iA = 0;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - i; j++)
            if (a[j] > a[i])
            {
                iA = a[j];
                a[j] = a[i];
                a[i] = iA;
            }
    }
}
void sort(float a[100], int len)
{
    float fA = 0;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - i; j++)
            if (a[j] > a[i])
            {
                fA = a[j];
                a[j] = a[i];
                a[i] = fA;
            }
    }
}

int main()
{
    int a[2] = {19, 1};
    float b[3] = {5.4, 2.3, 4.2};
    sort(a, 2);
    sort(b, 3);
    for (int i = 0; i < 2; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << b[i] << " ";
    }

    return 0;
}
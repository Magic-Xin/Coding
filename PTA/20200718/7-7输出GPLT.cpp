#include <bits/stdc++.h>
using namespace std;

int main()
{
    int G = 0, P = 0, L = 0, T = 0;
    string temp;
    cin >> temp;
    for (int i = 0; i < temp.length(); i++)
    {
        if (temp[i] == 'G' || temp[i] == 'g')
        {
            G++;
        }
        if (temp[i] == 'P' || temp[i] == 'p')
        {
            P++;
        }
        if (temp[i] == 'L' || temp[i] == 'l')
        {
            L++;
        }
        if (temp[i] == 'T' || temp[i] == 't')
        {
            T++;
        }
    }
    while (G > 0 || P > 0 || L > 0 || T > 0)
    {
        if (G)
        {
            cout << "G";
            G--;
        }
        if (P)
        {
            cout << "P";
            P--;
        }
        if (L)
        {
            cout << "L";
            L--;
        }
        if (T)
        {
            cout << "T";
            T--;
        }
    }
    return 0;
}
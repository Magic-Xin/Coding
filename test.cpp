#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
#define ll long long
using namespace std;

int main()
{
    int n, m, temp, k = 0;
    cin >> n >> m;
    int a[n];
    vector<int> b;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        b.push_back(temp);
    }
    sort(b.begin(), b.end());

    int i = 0, j = 0;
    for (i = 0; i < n; i++)
    {
        if(a[i] < b[0]) continue;
        for (j = 0; j < b.size(); j++)
        {
            if(b[j] == a[i])
            {
                k++;
                b.erase(b.begin()+j);
                break;
            }
            if(b[j] > a[i])
            {
                if(b[j-1] < a[i])
                {
                    k++;
                    b.erase(b.begin()+j-1);
                    break;
                }
                break;
            }
        }
    }
    cout << k << endl;
    return 0;
}
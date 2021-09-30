#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int a[10] = {0};
    string in;
    cin >> in;
    for (auto i : in)
    {
        if (i)
        {
            a[i - '0']++;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        if (a[i])
        {
            cout << i << ":" << a[i] << endl;
        }
    }
    return 0;
}
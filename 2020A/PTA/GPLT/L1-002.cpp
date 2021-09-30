#include <iostream>
using namespace std;

int main()
{
    int num, i, j, k, line;
    char ch;
    cin >> num >> ch;
    i = 2;
    while (i * i / 2 - 1 <= num)
    {
        i += 2;
    }
    line = i - 3;
    for (i = 1; i <= (line + 1) / 2; ++i)
    {
        for (j = 0; j < i - 1; ++j)
        {
            cout << " ";
        }
        for (k = 1; k <= line - j * 2; ++k)
        {
            cout << ch;
        }
        cout << endl;
    }
    for (i = (line + 1) / 2 + 1; i <= line; ++i)
    {
        for (j = 1; j <= line - i; ++j)
        {
            cout << " ";
        }
        for (k = 1; k <= line - (j - 1) * 2; ++k)
        {
            cout << ch;
        }
        cout << endl;
    }
    cout << num - (line + 1) * (line + 1) / 2 + 1 << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    double n = 0, res;
    int i;
    string input;
    cin >> input;
    if(input[0] == '-'){
        i = 1;
    }
    else{
        i = 0;
    }
    for (; i < input.length(); i++)
    {
        if (input[i] == '2')
        {
            n++;
        }
    }
    if (input[0] == '-')
    {
        if ((input[input.length() - 1] - '0') % 2 == 0)
        {
            res = n / (input.length() - 1) * 1.5 * 2 * 100;
        }
        else
        {
            res = n / (input.length() - 1) * 1.5 * 100;
        }
    }
    else
    {
        if ((input[input.length() - 1] - '0') % 2 == 0)
        {
            res = n / input.length() * 2 * 100;
        }
        else
        {
            res = n / input.length() * 100;
        }
    }
    printf("%.2lf%%", res);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void mod(string res, long long c)
{
    long long result = 0;
    for (int i = 0; i < res.size(); i++)
    {
        result = (result * 10 + (res[i] - '0')) % c;
    }
    cout << result;
    return;
}

string times(string a, string b)
{
    string result = "";
    int n = 0;
    deque<int> temp(a.size() + b.size() - 1, 0);
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            temp[i + j] += (a[i] - '0') * (b[j] - '0');
        }
    }
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        int m = temp[i] + n;
        temp[i] = m % 10;
        n = m / 10;
    }
    while (n != 0)
    {
        int t = n % 10;
        temp.push_front(t);
        n /= 10;
    }
    for (int i = 0 ; i < temp.size() ; i++)
    {
        ostringstream s;
        s << temp[i];
        result += s.str();
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a, b;
    long long c;
    cin >> a >> b >> c;
    mod(times(a, b), c);
    return 0;
}
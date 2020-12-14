#include <bits/stdc++.h>
using namespace std;

float make(float n, float m, char k)
{
    if (k == '+')
    {
        return n + m;
    }
    else if (k == '-')
    {
        return n - m;
    }
    else if (k == '*')
    {
        return n * m * 1.0;
    }
    else if (k == '/')
    {
        return n * 1.0 / m;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<float> res;
    string input;
    getline(cin, input);
    for (int i = input.length() - 1; i >= 0; i--)
    {
        string temp;
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
        {
            float n = res.back();
            res.pop_back();
            float m = res.back();
            res.pop_back();
            if(m==0 && input[i]=='/')
			 {
				 cout << "ERROR";
				 return 0;
			 }
            res.push_back(make(n, m, input[i]));
            i--;
        }
        else
        {
            while (input[i] != ' ' && i >= 0)
            {
                temp += input[i];
                i--;
            }
            res.push_back(atof(temp.c_str()));
        }
    }
    if (res.size() == 1)
    {
        printf("%0.1f\n", res.back());
    }
    else
    {
        cout << "ERROR";
    }
    return 0;
}
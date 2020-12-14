#include <bits/stdc++.h>
using namespace std;

struct INFO
{
    string num;
    int grade;
    int final;
    int local;
    int local_num;
};

bool cmp(const INFO &if1, const INFO &if2)
{
    return if1.grade > if2.grade;
}

void make_local(vector<INFO> &a)
{
    a[0].local = 1;
    int n = 1, m = 1;
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i].grade == a[i - 1].grade)
        {
            a[i].local = n;
            m++;
        }
        else
        {
            n += m;
            a[i].local = n;
            m = 1;
        }
    }
    return;
}

void make_final(vector<INFO> &a)
{
    a[0].final = 1;
    int n = 1, m = 1;
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i].grade == a[i - 1].grade)
        {
            a[i].final = n;
            m++;
        }
        else
        {
            n += m;
            a[i].final = n;
            m = 1;
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<INFO> info;
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<INFO> t;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            INFO temp;
            cin >> temp.num >> temp.grade;
            temp.local_num = i + 1;
            t.push_back(temp);
        }
        sort(t.begin(), t.end(), cmp);
        make_local(t);
        info.insert(info.end(), t.begin(), t.end());
    }
    cout << info.size() << endl;
    sort(info.begin(), info.end(), cmp);
    make_final(info);
    for (auto it = info.begin(); it != info.end(); it++)
    {
        cout << (*it).num << " " << (*it).final << " " << (*it).local_num << " " << (*it).local << endl;
        ;
    }
    return 0;
}
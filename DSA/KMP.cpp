#include<iostream>
#include<vector>
using namespace std;
int main()
{
	string a;
    cin >> a;
	int total = a.length();
	int i, j, t, h;
	vector<int> next;
	//初始化next数组
	for (i = 0; i < total; i++)
	{
		next.push_back(0);
	}
	next[0] = -1;
	//生成next数组
	for (i = 1; i < total; i++)//填a[i]的next值
	{
		for (j = i - 1; j > 0; j--)//向前追溯j个元素，即将a[i]的前j个元素逐个与开头比较
		{
			for (t = i - j, h = 0; t < i; h++, t++)//如果能走完这个循环，说明这j个元素成功匹配，即成功找到next[i]
			{
				if (a[t] != a[h])
				{
					break;
				}
			}
			if (t == i)//如果上述循环走完了
			{
				next[i] = j;
				break;
			}
		}
	}
	//输出
	for (i = 0; i < total; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;
	for (i = 0; i < total; i++)
	{
		cout << next[i]+1 << "  ";
	}
	return 0;
}


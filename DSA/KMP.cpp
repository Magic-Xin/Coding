#include <iostream>
#include <vector>
using namespace std;
int main()
{
	string a;
	cin >> a;
	int total = a.length();
	int i, j, t, h;
	vector<int> next;
	for (i = 0; i < total; i++)
	{
		next.push_back(0);
	}
	next[0] = -1;
	for (i = 1; i < total; i++)
	{
		for (j = i - 1; j > 0; j--)
		{
			for (t = i - j, h = 0; t < i; h++, t++)
			{
				if (a[t] != a[h])
				{
					break;
				}
			}
			if (t == i)
			{
				next[i] = j;
				break;
			}
		}
	}
	for (i = 0; i < total; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;
	for (i = 0; i < total; i++)
	{
		cout << next[i] + 1 << "  ";
	}
	return 0;
}

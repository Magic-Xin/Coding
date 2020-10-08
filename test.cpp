#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c, res;
	cin >> a >> b;
	c = a * b;
	res = 0;
	while (c)
	{
		res = c % 10 + res * 10;
		c /= 10;
	}
	cout << res;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c;
	vector<int> res;
	cin >> a >> b;
	c = a * b;
	while (c)
	{
		res.push_back(c%10);
		c /= 10;
	}
	for(auto i:res){
		cout << i;
	}
	return 0;
}
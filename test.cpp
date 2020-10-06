#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, j = 1, i = 32;
	unsigned long long m = 0;
	cin >> n;
	while(n){
		m += (n%2)*j;
		n /= 2;
		j *= 10;
		i--;
	}
	while(i--){
		cout << '0';
	}
	cout << m;
	return 0;
}
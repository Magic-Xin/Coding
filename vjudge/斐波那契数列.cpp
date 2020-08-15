#include<bits/stdc++.h>
using namespace std;

int f1, f2, n, k;
vector<int> f, kk;

void fibo(int step) {
    int temp;
    temp = f[step - 1] + f[step - 2];
    if (temp <= n) {
        f.push_back(temp);
        fibo(step + 1);
    }
    return;
}

int main() {
    while (cin >> f1 >> f2 >> n) {
        f.push_back(f1);
        f.push_back(f2);
        fibo(2);
        k = f.size();
        kk.push_back(k);
        f.clear();
    }
    for (auto i = kk.begin(); i != kk.end(); i++) {
        cout << *i << endl;
    }
    return 0;
}
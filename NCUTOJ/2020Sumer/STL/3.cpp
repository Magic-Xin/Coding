#include <bits/stdc++.h>
#define read(n) scanf("%d", &n)
#define readd(n, m) scanf("%d%d", &n, &m)
#define show(n) printf("%d ", n)
#define mst(n, m) memset(n, m, sizeof n)
using namespace std;

int main() {
    int n, m, k;
    readd(n, m), read(k);
    int a[n+1][m+1], b[n+1][m+1];
    mst(a, 0);
    mst(b, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            read(a[i][j]);
        }
    }
    while (k--) {
        int x1, y1, x2, y2;
        b[x1][y1]++;
        b[x2+1][y2+1]++;
        b[x1][y2+1]--;
        b[x2+1][y1]--;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m;j++) {
            b[i][j] += b[i-1][j]+b[i][j-1]-b[i-1][j-1];
            show(b[i][j] + a[i][j]);
        }
    }
}
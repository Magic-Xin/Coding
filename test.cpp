#include <stdio.h>
int main()
{
    int l, m, all = 0, end;
    scanf("%d%d", &l, &m);
    int a[m], b[m], c[m];
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &a[i], &b[i]);
        c[i] = b[i] - a[i];
        all += c[i];
    }
    end = l - all;
    printf("%d\n", end);
    return 0;
}

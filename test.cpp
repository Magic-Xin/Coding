#include <stdio.h>
int main()
{
    int l, m, all = 0, end;
    int a[m - 1], b[m - 1], c[m - 1];
    scanf("%d%d", &l, &m);
    for (int i = 0; i <= m - 1; i++)
    {
        scanf("%d%d", &a[i], &b[i]);
        c[i] = b[i] - a[i];
        all += c[i];
    }
    end = l - all;
    printf("%d\n", end);
    return 0;
}

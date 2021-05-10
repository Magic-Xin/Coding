#include <stdio.h>

int main()
{
    int i, n, l;
    int a[3], b[3], c[3];
    scanf("%d", &n);
    for (i = 0; i < 3; i++)
    {
        scanf("%d%d", &a[i], &b[i]);
    }

    for (i = 0; i < 3; i++)
    {
        c[i] = n / a[i] + 1;
    }
    if (c[0] > c[1])
    {
        if (c[1] > c[2])
            l = c[1];
        else
            l = c[2];
    }
    else
    {
        if (c[1] > c[2])
            l = c[1];
        else
            l = c[2];
    }
    printf("%d\n", l);
    return 0;
}
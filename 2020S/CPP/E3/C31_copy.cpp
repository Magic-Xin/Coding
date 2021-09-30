#include <iostream>

void sort(int a[100], int l)
{
    int temp = 0;
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < l - i; j++)
            if (a[j] > a[i])
            {
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
    }
}

void sort(double a[100], int l)
{
    double temp = 0;
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < l - i; j++)
            if (a[j] > a[i])
            {
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
    }
}

int main()
{
    int a[2] = {5, 4};
    double b[3] = {17.9987, 4.667, 1.10};
    sort(a, 2);
    sort(b, 3);
    for (int i = 0; i < 2; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%lf\t", b[i]);
    }

    return 0;
}
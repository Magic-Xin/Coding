#include<stdio.h>

int main() {
    int a[3];
    int b, i, n;
    for (n=0;n<3;n++) {
        scanf("%d", &a[n]);
    }
    for (n=1;n<3;n++) {
        b = a[n];
        i = n-1;
        while (i>=0 && a[i]>b) {
            a[i+1] = a[i];
            i--;
        }
        a[i+1] = b;
    }
    for (n=0;n<3;n++) {
        printf("%d ", a[n]);
    }
    return 0;
}
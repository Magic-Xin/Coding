#include<stdio.h>

int main(){
    int b, c, d, e, m, n, i;
    int k = 0;
    scanf("%d %d", &n, &b);
    n += 1;
    int a[n];
    for(i=0;i<n;i++){
        a[i] = 0;
    }
    for(c=1;c<=b;c++){
        scanf("%d %d", &d, &e);
        for(m=d;m<=e;m++){
            a[m] = 1;
        }
    }
    for(i=0;i<n;i++){
        if(a[i]==0){
            k++;
        }
    }
    printf("%d", k);
    return 0;
}
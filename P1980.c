#include<stdio.h>

int main(){
    int a, b, c, m, n, k;
    k = 0;
    scanf("%d %d", &a, &b);
    for(m=1;m<=a;m++){
        n = m;
        while(n>0){
            c = n%10;
            n /= 10;
            if (c==b){
                k++;
            }
        }
    }
    printf("%d", k);
    return 0;
}
#include<stdio.h>

int main(){
    float a, b, c;
    int n;
    b = 2;
    c = 0;
    scanf("%f", &a);
    for(n=1;n>0;n++){
        c += b;
        b *= 0.98;
        if (c > a){
            printf("%d", n);
            return 0;
        }
    }
}
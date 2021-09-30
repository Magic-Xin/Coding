#include<stdio.h>

int main(){
    float f, c;
    scanf("%f", &f);
    c = (f - 32) / 1.8;
    printf("%.2f\n", c);
    return 0;
}
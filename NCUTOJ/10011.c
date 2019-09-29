#include<stdio.h>

#define pi 3.14

int main(){
    float r, v;
    scanf("%f", &r);
    v = pi * r * r * r * 4 / 3;
    printf("%.2f", v);
    return 0;
}
#include<stdio.h>

int main(){
    float a[10] = {28.9, 32.7, 45.6, 78, 35, 86.2, 27.8, 43, 56, 65};
    float b[10];
    float sum = 0;
    int i;
    for(i = 0 ; i < 10 ; i++){
        scanf("%f", &b[i]);
        sum += a[i] * b[i];
    }
    printf("%.2f\n", sum);
    return 0;
}
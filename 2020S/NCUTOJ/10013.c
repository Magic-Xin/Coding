#include<stdio.h>

int main(){
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    int min1, min2, hour1, hour2;
    min1 = a % 100;
    min2 = b % 100;
    hour1 = a / 100;
    hour2 = b / 100;
    int hro, mino;
    hro = hour1 + hour2;
    mino = min1 + min2;
    while(mino >= 60){
        mino -= 60;
        hro++;
    }
    while(hro >= 24){
        hro -= 24;
    }
    printf("%d%.2d", hro, mino);
    return 0;
}
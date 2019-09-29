#include<stdio.h>

int main(){
    int a[10];
    int max=0, min=9999, sum=0;
    int i;
    for(i=0;i<10;i++){
        scanf("%d", &a[i]);
    }
    for(i=0;i<10;i++){
        if(a[i]>max){
            max = a[i];
        }
        if(a[i]<min){
            min = a[i];
        }
        sum += a[i];
    }
    printf("max=%d\nmin=%d\naverage=%d", max, min, sum/10);
    return 0;
}
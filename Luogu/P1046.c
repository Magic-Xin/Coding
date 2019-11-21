#include<stdio.h>

int main(){
    int a[10];
    int i, n, b;
    int k = 0;
    for(i=0;i<10;i++){
        scanf("%d", &a[i]);
    }
    scanf("%d", &b);
    b += 30;
    for(i=0;i<10;i++){
        n = a[i];
        if(n<=b){
            k++;
        }
    }
    printf("%d", k);
    return 0;
}
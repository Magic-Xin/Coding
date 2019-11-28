#include <stdio.h>

int min = 99999, max = -99999;
float ave = 0;

void count(int n){
    if(n < min){
        min = n;
    }
    if(n > max){
        max = n;
    }
    ave += n;
    return;
}

int main(){
    int n, i;
    scanf("%d", &n);
    int a[n];
    for(i = 0 ; i < n ; i++){
        scanf("%d", &a[i]);
        count(a[i]);
    }
    printf("%d %d %.2f", max, min, ave /= n);
    return 0;
}
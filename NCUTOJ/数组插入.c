#include<stdio.h>

int main(){
    int a[20];
    int n, m, i, j;
    for(i = 0 ; i < 20 ; ++i){
        scanf("%d", &n);
        if(n == 0){
            break;
        }
        else{
            a[i] = n;
        }
    }
    scanf("%d", &n);
    for(j = 0 ; j < i ; ++j){
        if(a[j] > n){
            for(m = i ; m >= j ; --m){
                a[m] = a[m-1];
            }
            a[j] = n;
            break;
        }
    }
    for(j = 0 ; j <= i ; ++j){
        printf("%d ", a[j]);
    }
    return 0;
}
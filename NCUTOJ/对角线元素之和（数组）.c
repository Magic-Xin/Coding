#include<stdio.h>

int main(){
    int i, j, n, sum = 0;
    scanf("%d", &n);
    int a[n][n];
    for(i = 0 ; i < n ; ++i){
        for(j = 0 ; j < n ; ++j){
            scanf("%d", &a[i][j]);
            if(i == j){
                sum += a[i][j];
            }
        }
    }
    printf("%d", sum);
    return 0;
}
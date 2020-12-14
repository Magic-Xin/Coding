#include<stdio.h>

int main(){
    int i, j, n, m, sum = 0;
    scanf("%d", &n);
    for(i = 0 ; i < n ; ++i){
        for(j = 0 ; j < n ; ++j){
            scanf("%d", &m);
            if(i == j){
                sum += m;
            }
        }
    }
    printf("%d", sum);
    return 0;
}
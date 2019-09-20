#include<stdio.h>

int main(){
    int n;
    int i, m, j;
    int k = 0;
    scanf("%d", &n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    for(i=0;i<n;i++){
        for(m=0;m<n;m++){
            for(j=m+1;j<n;j++){
                if(a[i] == a[m] + a[j]){
                    k++;
                    goto pos_1;
                }
                else{
                    continue;
                }
            }
        }
        pos_1: 
        i = i;
    }
    printf("%d", k);
    return 0;
}
#include<stdio.h>

int main(){
    int n, i, m;
    int k = 0;
    scanf("%d", &n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    for(i=0;i<n;i++){
        for(m=0;m<i;m++){
            if(a[m]<a[i]){
                k++;
            }
        }
        printf("%d ", k);
        k = 0;
    }
    return 0;
}
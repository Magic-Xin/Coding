#include<stdio.h>

int main(){
    int n, i, j;
    int k = 0;
    scanf("%d", &n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    for(i=1;i<n;i++){
        if(a[i]>a[i-1]){
            k++;
            if(k>j){
                j = k;
            }
        }
        else{
            k=0;
        }
    }
}
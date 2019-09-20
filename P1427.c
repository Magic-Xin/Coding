#include<stdio.h>

int main(){
    int i, b;
    int a[100];
    for(i=0;i<100;i++){
        scanf("%d", &b);
        if(b != 0){
            a[i] = b;
        }
        else{
            break;
        }
    }
    for(i=i-1;i>=0;i--){
        printf("%d ", a[i]);
    }
    return 0;
}
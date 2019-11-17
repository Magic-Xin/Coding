#include<stdio.h>

int main(){
    int i;
    for(i = 1 ; i <= 2; i++){
        continue;
    }
    printf("%d", i);
    return 0;
}
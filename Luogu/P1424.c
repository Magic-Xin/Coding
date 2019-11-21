#include<stdio.h>

int main(){
    int n, a, b, c, d;
    scanf("%d %d", &a, &b);
    for(n=1;n<=b;n++){
           d = (a+n-1) % 7;
        if(d==6 || d==0){
            continue;
        }
        else{
            c += 250;
        }
    }
    printf("%d", c);
    return 0;
}
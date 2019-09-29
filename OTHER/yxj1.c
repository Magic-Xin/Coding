#include<stdio.h>

int main(){
    int X, Y, Z;
    scanf("%d %d %d", &X, &Y,&Z);
    if(X<=Y && X<=Z && Y<=Z){
        printf("%d %d %d", X, Y, Z);
    }
    else if(X<=Y && X<=Z && Z<=Y){
        printf("%d %d %d", X, Z, Y);
    }
    else if(Y<=X && Y<=Z && X<=Z){
        printf("%d %d %d", Y, X, Z);
    }
    else if(Y<=X && Y<=Z && Z<=X){
        printf("%d %d %d", Y, Z, X);
    }
    else if(Z<=X && Z<=Y && X<=Y){
        printf("%d %d %d", Z, X, Y);
    }
    else if(Z<=X && Z<=Y && Y<=X){
        printf("%d %d %d", Z, Y, X);
    }
    return 0;
}
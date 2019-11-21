#include<stdio.h>

int n;

int root(int n){
    int temp = 0;
    while(n != 0){
        temp += n % 10;
        n /= 10;
    }
    if(temp >= 10){
        temp = root(temp);
    }
    return temp;
}

int main(){
    int i = 0, j;
    int a[1000];
    while(scanf("%d", &n) && n != 0){
        a[i] = root(n);
        i++;
    }
    for(j = 0 ; j < i ; j++){
        printf("%d\n", a[j]);
    }
    return 0;
}
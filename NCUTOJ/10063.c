#include<stdio.h>

int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int n;

int main(){
    int i, j;
    scanf("%d", &n);
    for(i = 0 ; i < 12 ; i++){
        j = 1;
        while(j <= month[i]){
            if(j == 13 && n == 5){
                printf("%d\n", i + 1);
            }
            n++;
            if(n > 7){
                n -= 7;
            }
            j++;
        }
    }
    return 0;
}

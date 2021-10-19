#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    float sum = 1.0;
    float i, j;
    j = 0.0;

    for(int k = 2 ; k <= n ; k++){
        j++;
        i = k;
        if(k % 2 == 0){
            sum -= i / (i + j);
        }
        else{
            sum += i / (i + j);
        }
    }
    
    printf("sum=%.3f\n", sum);
    return 0;
}
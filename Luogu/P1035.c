#include<stdio.h>

int main(){
    int n;
    float k, m;
    double s = 0;
    scanf("%f", &k);
    for(n=1;n>0;n++){
        m = n;
        s += (1.0 / m);
        if (s > k){
            printf("%d", n);
            return 0;
        }
    }
}
#include<stdio.h>

int main(){
    int a; //铅笔数量
    scanf("%d", &a);
    int i; //循环参数
    int b, c; //b是一包内的数量，c是一包单价
    int d; //对于单个种类的总价
    int e = 9999999;
    for (i=1;i<=3;i++){
        scanf("%d %d", &b, &c);
        if (a%b==0){
            d = (a / b) * c;
        }
        else{
            d = (a / b) + 1;
            d *= c;
        }
        if (d < e){
            e = d;
        }
        }
    printf("%d", e);
    return 0;
}
#include<stdio.h>
#include<string.h>

int n;

struct A{
    char num[11];
    int sc[5];
    int k;
    float avg;
} a[30];

int main(){
    int i, j;
    float m = 0;
    scanf("%d", &n);
    for(i = 0 ; i < n ; i++){
        a[i].k = 0;
        a[i].avg = 0;
        scanf("%s%d%d%d%d%d", &a[i].num, &a[i].sc[0], &a[i].sc[1], &a[i].sc[2], &a[i].sc[3], &a[i].sc[4]);
        for(j = 0 ; j < 5 ; j++){
            a[i].avg += a[i].sc[j];
            if(a[i].sc[j] < 60){
                a[i].k++;
            }
        }
        a[i].avg /= 5;
        m += a[i].sc[0];
    }
    printf("%.2f\n", m /= n);
    for(i = 0 ; i < n ; i++){
        if(a[i].k >= 2){
            printf("%s ", a[i].num);
            j = -1;
        }
    }
    if(j != -1){
        printf("no");
    }
    printf("\n");
    for(j = 0 ; j < n ; j++){
        if(a[j].avg >= 90.0){
            printf("%s ", a[j].num);
            i = -1;
        }
    }
    if(i != -1){
        printf("no");
    }
    return 0;
}


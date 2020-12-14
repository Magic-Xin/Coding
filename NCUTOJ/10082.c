#include<stdio.h>
#include<string.h>

struct A{
    char name[30];
    char public[20];
    int  numb;
    float p;
} a[51];

float add(int n){
    int i;
    float k = 0;
    for(i = 0 ; i < n ; i++){
        k += a[i].numb * a[i].p;
    }
    return k;
}

void sort(int n){
    int i, j;
    for(i = 0 ; i < n - 1 ; i++){
        for(j = i + 1 ; j < n ; j++){
            if(a[j].p < a[i].p){
                a[50] = a[i];
                a[i] = a[j];
                a[j] = a[50];
            }
        }
    }
    return;
}

int main(){
    int n, i;
    float k;
    scanf("%d\n", &n);
    for(i = 0 ; i < n ; i++){
        scanf("%s%s%d%f", &a[i].name, &a[i].public, &a[i].numb, &a[i].p);
    }
    sort(n);
    k = add(n);
    for(i = 0 ; i < n ; i++){
        printf("%-30s%-20s%-10d%-.2f\n", a[i].name, a[i].public, a[i].numb, a[i].p);
    }
    printf("%.2f", k);
    return 0;
}
#include<stdio.h>
#include<string.h>

int n;

struct date{
    char number[11];
    int month;
    int day;
} a[200];

struct out{
    char number[10000];
    int month;
    int day;
} b[201];

void prt(int m){
    int i;
    for(i = 0 ; i < m ; i++){
        printf("%d %d %s\n", b[i].month, b[i].day, b[i].number);
    }
    return;
}

void sort(int m){
    int i, j;
    for(i = 0 ; i < m ; i++){
        for(j = i ; j < m ; j++){
            if((b[i].month > b[j].month) || (b[i].month == b[j].month && b[i].day > b[j].day)){
                b[200] = b[j];
                b[j] = b[i];
                b[i] = b[200];
            }
        }
    }
    prt(m);
    return;
}

void cmp(){
    int i, j, k, m = 0;
    for(i = 0 ; i < n ; i++){
        if(a[i].month == 0 && a[i].day == 0){
            continue;
        }
        k = 0;
        memset(b[m].number, 0, sizeof(b[m].number));
        for(j = i + 1 ; j < n ; j++){
            if(k != 0 && a[i].month == a[j].month && a[i].day == a[j].day){
                strcat(b[m].number, a[j].number);
                strcat(b[m].number, " ");
                a[j].month = 0;
                a[j].day = 0;
            }
            else if(a[i].month == a[j].month && a[i].day == a[j].day){
                b[m].month = a[i].month;
                b[m].day = a[i].day;
                strcpy(b[m].number, a[i].number);
                strcat(b[m].number, " ");
                strcat(b[m].number, a[j].number);
                strcat(b[m].number, " ");
                a[j].month = 0;
                a[j].day = 0;
                k = 1;
            }
        }
        if(k == 0){
            b[m].month = a[i].month;
            b[m].day = a[i].day;
            strcpy(b[m].number, a[i].number);
        }
        m++;
    }
    sort(m);
    return;
}

int main(){
    int i;
    scanf("%d", &n);
    for(i = 0 ; i < n ; i++){
        scanf("%s%d%d", &a[i].number, &a[i].month, &a[i].day);
    }
    cmp();
    return 0;
}

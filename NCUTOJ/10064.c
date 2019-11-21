#include<stdio.h>
#include<string.h>

char a[1000];
char maxl;
int max;

struct SUM{
    char maxl;
    int max;
};

void cmp(){
    char temp;
    int i, k;
    maxl = 'a';
    max = 0;
    for(temp = 'a' ; temp <= 'z' ; temp++){
        k = 0;
        for(i = 0 ; i < strlen(a) ; i++){
            if(a[i] == temp){
                k++;
            }
        }
        if(k > max){
            maxl = temp;
            max = k;
        }
    }
    return;
}

int main(){
    int i, n;
    scanf("%d\n", &n);
    struct SUM sum[n];
    for(i = 0 ; i < n ; i++){
        fgets(a, 1000, stdin);
        cmp();
        sum[i].maxl = maxl;
        sum[i].max = max;
        memset(a, 0, sizeof(a));
    }
    for(i = 0 ; i < n ; i++){
        printf("%c %d\n", sum[i].maxl, sum[i].max);
    }
    return 0;
}


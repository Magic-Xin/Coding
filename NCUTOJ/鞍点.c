#include<stdio.h>


int main(){
    int m, n, i, j, k;
    int temp, r;
    scanf("%d%d", &m, &n);
    int a[m][n];
    for(i = 0 ; i < m ; ++i){
        for(j = 0 ; j < n ; ++j){
            scanf("%d", &a[i][j]);
        }
    }
    for(i = 0 ; i < m ; ++i){
        temp = -10000;
        for(j = 0 ; j < n ; ++j){
            if(a[i][j] > temp){
                temp = a[i][j];
                r = j;
            }
        }
        for(k = 0 ; k < m ; ++k){
        	if(a[k][r] < temp){
        		break;
			}
		}
		if(k == m){
			printf("%d %d %d", i, r, temp);
			return 0;
		}
    }
    printf("no");
    return 0;
}




#include<bits/stdc++.h>
using namespace std;

int k[100][100], j[100][100];

void cmp(int c, int d){
    int b, i;
    for(int n = 1 ; n < d ; n++){
        b = k[c][n];
        i = n-1;
        while(i >= 0 && k[c][i] > b){
            k[c][i+1] = k[c][i];
            i--;
        }
        k[c][i+1] = b;
    }
    return 
 }

int main(){
    int n, m = 0, temp;
    while(cin >> n){
        for(int i = 0 ; i < n ; i++){
            cin >> temp;
            if(temp < 0){
                k[m][i] = -temp;
                j[m][i] = 1;
            }
            else{
                k[m][i] = temp;
                j[m][i] = 0;
            }
        }
        cmp(m, n);
        m++;
    }
    for(int p = 0 ; p < m ; p++){
        
    }
}
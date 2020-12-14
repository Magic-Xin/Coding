#include<bits/stdc++.h>
using namespace std;

int a[100][100], b[100][100];
int k;

void sort(){
    int temp1, temp2, i, j;
    for(j = 2 ; j <= a[k][0] ; j++){
        temp1 = a[k][j];
        temp2 = b[k][j];
        i = j - 1;
        while(i >= 1 && a[k][i] > temp1){
            a[k][i+1] = a[k][i];
            b[k][i+1] = b[k][i];
            i--;
        }
        a[k][i+1] = temp1;
        b[k][i+1] = temp2;
    }
    return;
}

int main(){
    k = 0;
    while(cin >> a[k][0]){
        if(a[k][0] == 0){
            break;
        }
        for(int i = 1; i <= a[k][0] ; i++){
            cin >> a[k][i];
            if(a[k][i] < 0){
                a[k][i] = -a[k][i];
                b[k][i] = 1;
            }
        }
        sort();
        k++;
    }
    k = 0;
    while(a[k][0] != 0){
        for(int i = a[k][0] ; i > 1 ; i--){
            if(b[k][i]){
                cout << -a[k][i] << " ";
            }
            else{
                cout << a[k][i] << " ";
            }
        }
        cout << a[k][1] << endl;
        k++;
    }
    return 0;
}
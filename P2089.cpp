#include<bits/stdc++.h>
using namespace std;

int n, k;
int a[10] = {0};

void plan_2(){
    
}

void plan_1(){
    for(int i = 9 ; i >= 0 ; i--){
        while(a[i] < 4){
            a[i]++;
            if(a[0] + a[1] + a[2] + a[3] + a[4] + a[5] + a[6] + a[7] + a[8] + a[9] == n){
                plan_2();
            }
        }
    }
}
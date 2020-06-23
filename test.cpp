#include<bits/stdc++.h>
using namespace std;

int main(){
    int* p;
    p = new int[10];

    for(int i = 0 ; i < 10 ; i++){
        p[i] = i;
    }

    for(int i = 0 ; i < 10 ; i++){
        *p = i;
        p++;
        printf("p[%d]: %d;\n", i, p[i]);
    }

    //delete[] p;
    return 0;
}
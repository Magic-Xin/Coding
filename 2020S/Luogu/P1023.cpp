#include<bits/stdc++.h>
using namespace std;

int expe, base, redu, i, m, n, temp, k = 0;
int a[100000] = {0};

void revenue(){
    int b[100000] = {0};
    int max = -100000000, imax;
    for(int rev = -1000 ; rev < 1000 ; rev++){
        for(int j = base ; j <= i ; j++){
            b[j] = (j - base + rev) * a[j];
        }
        for(int j = base ; j <= i ; j++){
            if(b[j] > max){
                max = b[j];
                imax = j;
            }
        }
        if(imax == expe){
            cout << rev;
            k++;
            break;
        }
    }
    return;
}

void reduce(){
    for(i = m + 1 ;i < 100000 ; i++){
        n -= redu;
        if(n > 0){
            a[i] = n;
        }
        else{
            break;
        }
    }
    return;
}

int main(){
    cin >> expe;
    base = 99999;
    for(i = 0 ; i < 100000 ;){
        cin >> i >> temp;
        if(i == -1 && temp == -1){
            break;
        }
        else{
            a[i] = temp;
            m = i;
            n = temp;
            if(i < base){
                base = i;
            }
        }
    }
    cin >> redu;
    reduce();
    revenue();
    if(k == 0){
        cout << "NO SOLUTION";
    }
    return 0;
} 
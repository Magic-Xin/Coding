#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

char c,a;
int f = 1, now = 1, k, b, x;
bool r;
double sum;

int main(){
    while(cin >> c)
    {
        if(c == '-'){
            b += now * f * x;
            x = 0;
            f = -1;
            r = 0;
        }
        if(c == '+'){
            b += now * f * x;
            x = 0;
            f = 1;
            r = 0;
        }
        if(c == '='){
            b += now * f * x;
            x = 0;
            f = 1;
            now = -1;
            r = 0;
        }
        if(c >= 'a' && c <= 'z')
        {
            if(r)
            {
                k += now * f * x;
                x = 0;
            }
            else{
                k += now * f;
            }
            a = c;
            r = 0;
        }
        if(c >= '0' && c <= '9'){
            x = x * 10 + c - '0';
            r = 1;
        }
    }
    b += now * f * x;
    sum = double(-b * 1.0 / k);
    if(sum == -0.0){
        printf("%c=0.000", a);
    }
    else{
        printf("%c=%.3lf", a, sum);
    }
    return 0;
}
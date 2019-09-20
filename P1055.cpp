#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    char a[10];
    scanf("%c-%c%c%c-%c%c%c%c%c-%c", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6], &a[7], &a[8], &a[9]);
    int b, c, d;
    b = (a[0]-48)*1 + (a[1]-48)*2 + (a[2]-48)*3 +(a[3]-48)*4 + (a[4]-48)*5 + (a[5]-48)*6 + (a[6]-48)*7 + (a[7]-48)*8 + (a[8]-48)*9;
    c = b % 11;
    if(a[9] == 88){
        d = 10;
    }
    else{
        d = a[9] - 48;
    }
    if (c == d){
        cout << "Right" << endl;
    }
    else{
        if(c == 10){
            a[9] = 88;
            printf("%c-%c%c%c-%c%c%c%c%c-%c", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);
        }
        else{
            a[9] = c + 48;
            printf("%c-%c%c%c-%c%c%c%c%c-%c", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);
        }
        
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int i, n;
    string in1, in2;
    getline(cin, in1);
    getline(cin, in2);
    n = in2.length();
    char a[n], b[n];
    int nn = atoi(in1.c_str());
    strcpy(a, in2.data());
    nn %= 26;
    for(i = 0 ; i < n ; i++){
        a[i] = toupper(a[i]);
        b[i] = a[i] + nn;
        while(b[i] > 90){
            b[i] -= 26;
        }
        b[i] = tolower(b[i]);
        cout << b[i];
    }
    return 0;
}

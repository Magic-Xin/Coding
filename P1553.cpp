#include<bits/stdc++.h>
#include<string>
using namespace std;


int main(){
    string a;
    getline(cin, a);
    int l;
    l = a.length();
    char cache[l];
    strcpy(cache, a);

    vector<char> fr;
    vector<char> bk;
    for(int i = 0; i < l; i++){
        if(cache[i] == '.' || cache[i] == '/' || cache[i] == '%'){
            goto pos_1;
        }
        else{
            fr.push_back(a[i]);
        }
        if(cache[i] != 00000){
            pos_1:
            bk.push_back(a[i]);
        }
    }
    for(long unsigned int i = 0 ; i < fr.size() ; i++){
        cout << fr[i];
    }
    return 0;
}
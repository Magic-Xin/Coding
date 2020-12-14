#include<bits/stdc++.h>
using namespace std;

long long int a, temp;
bool r = 0;
vector<int> b;

int main(){
    cin >> a;
    if(a < 0){
        cout << "-";
        a = -a;
    }
    temp = a;
    while(temp != 0){
        b.push_back(temp % 10);
        temp /= 10;
    }
    for(auto i = b.begin() ; i < b.end() ; i++){
        if(*i == 0 && r == 0){
            continue;
        }
        else{
            r = 1;
            cout << *i;
        }
    }
    return 0;
}
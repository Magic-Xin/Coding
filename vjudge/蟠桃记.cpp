#include<bits/stdc++.h>
using namespace std;

int n, a;
vector<int> sum;

void half(int step){
    a++;
    a *= 2;
    step--;
    if(step > 0){
        half(step);
    }
    return;
}

int main(){
    while(cin >> n){
        a = 1;
        half(n-1);
        sum.push_back(a);
    }
    for(auto i = sum.begin() ; i != sum.end() ; i++){
        cout << *i << endl;
    }
}
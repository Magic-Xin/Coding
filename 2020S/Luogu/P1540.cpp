#include<bits/stdc++.h>
using namespace std;

int m, n, x, k = 0;
vector<int> a;

void dic(){
    while(cin >> x){
        if(find(a.begin(), a.end(), x) == a.end()){
            ++k;
            a.push_back(x);
        }
        if(a.size() > m){
            a.erase(a.begin());
        }
    }
    return;
}

int main(){
    cin >> m >> n;
    dic();
    cout << k;
    return 0;
}
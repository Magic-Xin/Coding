#include<bits/stdc++.h>
using namespace std;

int n, s, a, b, c, xi, yi;
int k = 0;
vector<int> y;

void out(){
    sort(y.begin(), y.end());
    for(auto i = y.begin() ; i != y.end() ; i++){
        s -= *i;
        if(s < 0){
            break;
        }
        else{
            k++;
        }
    }
    return;
}

void in(){
    for(int i = 0 ; i < n ; i++){
        cin >> xi >> yi;
        if(xi <= c){
            y.push_back(yi);
        }
    }
    out();
    return;
}

int main(){
    cin >> n >> s;
    cin >> a >> b;
    c = a + b;
    in();
    cout << k;
    return 0;
}
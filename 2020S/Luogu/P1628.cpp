#include<bits/stdc++.h>
using namespace std;

vector<string> res;

void find_s(vector<string> a, string t){
    int j;
    for(int i = 0 ; i < a.size() ; i++){
        for( j = 0 ; j < t.length() ; j++){
            if(a[i][j] != t[j]){
                break;
            }
        }
        if(j == t.length()){
            res.push_back(a[i]);
        }
    }
    return;
}

int main(){
    int n;
    cin >> n;
    vector<string> a;
    string t;
    while(n--){
       cin >> t;
       a.push_back(t);
    }
    cin >> t;
    sort(a.begin(), a.end());
    find_s(a, t);
    for(auto i:res){
        cout << i << endl;
    }
    return 0;
}
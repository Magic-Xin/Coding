#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a;
    vector<int>::iterator it;
    int m, n, temp;
    scanf("%d%d", &n, &m);
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &temp);
        a.push_back(temp);
    }
    for(int i = 0 ; i < m ; i++){
        scanf("%d", &temp);
        it = lower_bound(a.begin(), a.end(), temp);
        cout << it - a.begin();
        if(i < m - 1){
            printf(" ");
        }
    }
    return 0;
}
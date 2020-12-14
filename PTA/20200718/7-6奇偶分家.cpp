#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, temp, ji, ou;
    cin >> n;
    ji = 0, ou = 0;
    while(n--){
        cin >> temp;
        if(temp % 2 == 0){
            ou++;
        }
        else{
            ji++;
        }
    }
    cout << ji << " " << ou << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int n;

int main(){
    cin >> n;
    int a[n + 1];
    for(int i = n ; i > 0 ; --i){
        cin >> a[i];
        if(a[i] == 1 && i != n && i != 1){
            cout << "+x^" << i;
        }
        else if(a[i] == 1 && i == n){
            cout << "x^" << i;
        }
        else if(a[i] == -1 && i != 1){
            cout << "-x^" << i;
        }
        else if(a[i] == 1 && i != n && i == 1){
            cout << "+x";
        }
        else if(a[i] == 1 && i == n && i== 1){
            cout << "x";
        }
        else if(a[i] == -1 && i == 1){
            cout << "-x";
        }
        else if(a[i] == 0){
            continue;
        }
        else if(a[i] > 0 && i != n && i == 1){
            cout << "+" << a[i] << "x";
        }
        else if(a[i] > 0 && i == n && i == 1){
            cout << a[i] << "x";
        }
        else if(a[i] < 0 && i == 1){
            cout << a[i] << "x";
        }
        else if(a[i] > 0 && i != n){
            cout << "+" << a[i] << "x^" << i;
        }
        else if(a[i] < 0 && i == n){
            cout << a[i] << "x^" << i;
        }
        else{
            cout << a[i] << "x^" << i;
        }
    }
    cin >> a[0];
    if(a[0] > 0){
        cout << "+" << a[0] << endl;
    }
    else if(a[0] < 0){
        cout << a[0] << endl;
    }
    return 0;
}
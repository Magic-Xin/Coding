#include<bits/stdc++.h>
using namespace std;\

int main(){
    string a;
    getline(cin, a);
    int n;
    n = a.length();
    char d[n];
    strcpy(d, a.data());

    vector<char> b, c, e;
    int k = 0;
    int p = 0;
    for(long unsigned int i = 0 ; i < n; i++){
        if(d[i] != '.' && d[i] != '/' && d[i] != '%'){
            b.push_back(d[i]);
        }
        else if(d[i] == '.'){
            for(i = i + 1 ; i < n ; i++){
                c.push_back(d[i]);
            }
            for(auto it = c.end() - 1 ; it != c.begin() - 1 ; it-- ){
                e.push_back(*it);
            }
            for(auto it = e.end() - 1 ; it != e.begin() - 1 ; it--){
                if(*it != 48){
                    break;
                }
                p++;
            }
            e.resize(e.size() - p);
            if(e.size() == 0){
                e.push_back('0');
            }
            
            k = 1;
            break;
        }
        else if(d[i] == '/'){
            for(i = i + 1 ; i < n ; i++){
                c.push_back(d[i]);
            }
            for(auto it = c.end() - 1 ; it != c.begin() ; it--){
                if(*it != 48){
                    break;
                }
                p++;
            }
            c.resize(c.size() - p);
            k = 2;
            break;
        }
        else if(d[i] == '%'){
            k = 3;
            break;
        }
    }
    p = 0;
    for(auto it = b.end() - 1 ; it != b.begin() ; it--){
        if(*it != 48){
            break;
        }
        p++;
    }
    b.resize(b.size() - p);
    if(b.size() == 0){
        b.push_back('0');
    }
    if(k == 0){
        for(int i = b.size() - 1 ; i >= 0 ; i--){
            cout << b[i];
        }
    }
    else if(k == 1){
        for(int i = b.size() - 1 ; i >= 0 ; i--){
            cout << b[i];
        }
        cout << ".";
        for(int i = 0 ; i < e.size() ; i++){
            cout << e[i];
        }
    }
    else if(k == 2){
        for(int i = b.size() - 1 ; i >= 0 ; i--){
            cout << b[i];
        }
        cout << "/";
        for(int i = c.size() - 1 ; i >= 0 ; i--){
            cout << c[i];
        }
    }
    else if(k == 3){
        for(int i = b.size() - 1 ; i >= 0 ; i--){
            cout << b[i];
        }
        cout << "%";
    }
    return 0;
}
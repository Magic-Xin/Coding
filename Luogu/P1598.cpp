#include<bits/stdc++.h>
using namespace std;

int main(){
    char stc[100];
    int t[26] = {0};
    int m, n;
    for(int i = 0; i < 4 ; i++){
        cin.getline(stc, 100);
        n = strlen(stc);
        for(int ii = 0 ; ii < n ; ii++){
            if(stc[ii] > 64 && stc[ii] < 91){
                m = stc[ii] - 65;
                t[m]++;
            }
            else{
                continue;
            }
        }
        memset(stc, '\0', sizeof(stc));
    }
    m = 0;
    for(int i = 0 ; i < 26 ; i++){
        m = max(m, t[i]);
    }
    for(int i = m ; i != 0 ; i--){
        for(int ii = 0 ; ii < 26 ; ii++){
            if(t[ii] >= i){
                cout << "* ";
            }
            else{
                cout << "  ";
            }
        }
        cout << "\n";
    }
    cout << "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
    return 0;
}
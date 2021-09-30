#include<bits/stdc++.h>
using namespace std;

int main(){
    string time;
    cin >> time;
    int hours = 0;
    hours += (time[1] - '0') + (time[0] - '0') * 10;
    if(hours < 12 || time == "12:00"){
        cout << "Only " << time << ".  Too early to Dang.";
    }
    else if(time[3] == '0' && time[4] == '0'){
        for(int i = 12 ; i < hours ; i++){
            cout << "Dang";
        }
    }
    else{
        for(int i = 12 ; i < hours ; i++){
            cout << "Dang";
        }
        cout << "Dang";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    string a, b;
    int n, m;
    getline(cin, a);
    getline(cin, b);
    n = a.length();
    m = b.length();
    for(int i = 0; i < n; i++){
        a[i] = tolower(a[i]);
    }
    for(int i = 0; i < m; i++){
        b[i] = tolower(b[i]);
    }
    //计算两个输入的长度，并转化为小写

    vector<char>word;
    int k = 0, p = 0;
    int position = 999;
    int r;
    for(unsigned int i = 0; i < m; i++){
        r = i;
        for(unsigned int l = 0; l < m; l++){
            if(b[i] != ' '){
                word.push_back(b[i]);
                i++;
                continue;
            }
            else{
                break;
            }
        }   //单词拆分
        for(unsigned int j = 0; j < word.size(); j++){
            if(word[j] == a[j]){
                k++;
                continue;
            }
            else{
                k = 0;
                break;
            }
        }   //单词比对
        if(k != 0){
            p++;
            position = min(position, r);
        }
        word.clear();
    }
    if(p == 0){
        cout << "-1" << endl;
    }
    else{
        cout << p << " " << position;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int n[10000] = {5, 7, 11};
vector<int> m;
int a, b, p1, p2, p3, p4, p5, p6;

void prime(){
    int i, temp, j;
    j = 3;
    sort(m.begin(), m.end());
    for(auto it = m.begin() ; it != m.end() ; it++){
        temp = sqrt(*it) + 1;
        for(i = 2 ; i < temp ; i++){
            if(*it % i == 0){
                break;
            }
        }
        if(i == temp){
            n[j] = *it;
            j++;
        }
    }
    return;
}

void palindrome(){
    int d1, d2, d3, d4;
    for(d1 = 1; d1 < 10 ; d1++){
        for(d2 = 0 ; d2 < 10 ; d2++){
            p1 = d1 * 100 + d2 * 10 + d1;
            m.push_back(p1);
            p2 = d1 * 1000 + d2 * 100 + d2 * 10 + d1;
            m.push_back(p2);
            for(d3 = 0 ; d3 < 10 ; d3++){
                p3 = d1 * 10000 + d2 * 1000 + d3 * 100 + d2 * 10 + d1;
                m.push_back(p3);
                p4 = d1 * 100000 + d2 * 10000 + d3 * 1000 + d3 * 100 + d2 * 10 + d1;
                m.push_back(p4);
                for(d4 = 0 ; d4 < 10 ; d4++){
                    p5 = d1 * 1000000 + d2 * 100000 + d3 * 10000 + d4 * 1000 + d3 * 100 + d2 * 10 + d1;
                    m.push_back(p5);
                    p6 = d1 * 10000000 + d2 * 1000000 + d3 * 100000 + d4 * 10000 + d4 * 1000 + d3 * 100 + d2 * 10 + d1;
                }
            }
        }
    }
    prime();
    return;
}

int main(){
    cin >> a >> b;
    if(b < 100){
        for(int i = 0 ; i < 3 ; i++){
            if(n[i] >= a && n[i] <= b){
                cout << n[i] << endl;
            }
        }
    }
    else{
        palindrome();
        for(int i = 0 ; i < 10000 ; i++){
            if(n[i] >= a && n[i] <= b){
                cout << n[i] << endl;
            }
        }
    }
    return 0;
}
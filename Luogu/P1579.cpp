#include<bits/stdc++.h>
using namespace std;

int in;
vector<int> p;

void prime(int n){
    int i, temp;
    temp = sqrt(n) + 1;
    for(i = 2 ; i < temp ; i++){
        if(n % i == 0){
            break;
        }
    }
    if(i == temp){
        p.push_back(n);
    }
    return;
}

void make_prime(){
    for(int i = 2 ; i < 20000 ; i++){
        prime(i);
    }
}

void compare(){
    for(auto a = p.begin() ; a != p.end() ; a++){
        for(auto b = p.begin() ; b != p.end() ; b++){
            for(auto c = p.begin() ; c != p.end() ; c++){
                if(*a + *b + *c == in){
                    cout << *a << " " << *b << " " << *c;
                    goto pos_1;
                }
            }
        }
    }
    pos_1:
    return;
}

int main(){
    cin >> in;
    make_prime();
    compare();
    return 0;
}
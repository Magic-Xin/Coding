#include<bits/stdc++.h>
using namespace std;

double s, x, lf, rt;
double p = 7, n = 0;

int main(){
    cin >> s >> x;
    lf = s - x;
    rt = s + x;
    for(int i = 0 ; i < 20 ; i++){
        if(n >= lf && n <= rt){
            n += p;
            if(n >= lf && n <= rt){
                cout << "y" << endl;
                return 0;
            }
            else{
                cout << "n" << endl;
                return 0;
            }
        }
        n += p;
        p *= 0.98;
   }
   cout << "n" << endl;
   return 0;
}
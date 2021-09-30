#include<bits/stdc++.h>
using namespace std;

struct TV{
	int t1;
	int t2;
} a[105]; 
 
int compare(TV p,TV q){
	if(p.t2 == q.t2){
        return p.t1 > q.t1;
    }	
	return p.t2 < q.t2;
}
 
int main(){
	int n, j, k, t;
    cin >> n;
	for(int i = 0 ; i < n ; i++){
        cin >> a[i].t1 >> a[i].t2;
    }
	sort(a, a+n, compare);
	for(int i = 1 ; i < n ; i++){
        t = a[0].t2;
        k = 1;
		if(a[i].t1 >= t){
			t = a[i].t2;
			k++;
		}
	}
	cout << k << endl;
	return 0;
}
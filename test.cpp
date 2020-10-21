#include <iostream>
#include <math.h>
using namespace std;

template<class T>
T add(T x, T y){
	if(x>y){
		return x;
	}
	else{
		return y;
	}
}

int main()
{
	int a[5], int_m = 0;
	float b[5], float_m = 0;
	for(int i  = 0 ; i < 5 ; i++){
		cin >> a[i];
	}
	for(int i  = 0 ; i < 5 ; i++){
		cin >> b[i];
	}
	for(int i = 0 ; i < 5 ; i++){
		int_m = add(a[i], int_m);
	}
	for(int i = 0 ; i < 5 ; i++){
		float_m = add(b[i], float_m);
	}
	cout << int_m << endl;
	cout << float_m << endl;
	return 0;
}
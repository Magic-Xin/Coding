<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;



int main(void)
{
    string i = "13142223336";
	cout << i.length() ;
	return 0;
=======
#include<bits/stdc++.h>
using namespace std;

int main(){
    int* p;
    p = new int[10];

    for(int i = 0 ; i < 10 ; i++){
        p[i] = i;
    }

    for(int i = 0 ; i < 10 ; i++){
        *p = i;
        p++;
        printf("p[%d]: %d;\n", i, p[i]);
    }

    //delete[] p;
    return 0;
>>>>>>> b62fbd2b4c1f5a96e2ddf5436547f4bf7dfa9031
}
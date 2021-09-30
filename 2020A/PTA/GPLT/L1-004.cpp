#include <iostream>
using namespace std;

int main(){
    double f, c;
    cin >> f;
    c = 5 * (f-32) /9;
    cout << "Celsius = " << (int)c << endl;
    return 0;
}
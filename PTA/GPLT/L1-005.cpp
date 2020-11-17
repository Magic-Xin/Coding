#include <iostream>
#include <cstring>
using namespace std;

struct Student{
    string a_num;
    int b_num, c_num;
};

int main(){
    int n;
    cin >> n;
    Student stu[n];
    for(int i = 0 ; i < n ; i++){
        cin >> stu[i].a_num >> stu[i].b_num >> stu[i].c_num;
    }
    int m;
    cin >> m;
    while(m--){
        int temp;
        cin >> temp;
        for(auto i:stu){
            if(i.b_num == temp){
                cout << i.a_num << " " << i.c_num << endl;
                break;
            }
        }
    }
    return 0;
}
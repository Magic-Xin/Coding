#include<bits/stdc++.h>
using namespace std;

class Student{
    public:
        int num;
        char name;
        int age;
};

void start(Student* stu1, Student*stu2){
    stu1->num = 0;
    stu1->name = 'a';
    stu1->age = 0;
    stu2->num = 1;
    stu2->name = 'b';
    stu2->age = 1;
    return;
}

int main(){
    Student* stu1 = new Student();
    Student* stu2 = new Student();
    start(stu1, stu2);
    swap(stu1, stu2);
    delete stu1;
    delete stu2;
    return 0;
}
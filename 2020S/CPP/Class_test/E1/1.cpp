#include <iostream>

class Student
{
public:
    int num;
    char name;
    int age;
};

int main()
{
    Student *stu1 = new Student();
    Student *stu2 = new Student();

    stu1->num = 001;
    stu1->name = 'A';
    stu1->age = 10;
    stu2->num = 002;
    stu2->name = 'B';
    stu2->age = 35;

    std::swap(stu1, stu2);

    delete stu1;
    delete stu2;

    return 0;
}
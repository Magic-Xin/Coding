#include <bits/stdc++.h>
using namespace std;

class Student
{
private:
    int num;
    string name;
    int age;

public:
    Student(int a, string b, int c);
    ~Student();
    void display();
};

Student::Student(int a, string b, int c) : num(a), name(b), age(c)
{
}

Student::~Student() {}

void Student::display()
{
    cout << num << " " << name << " " << age << endl;
}

int main()
{
    Student* stu1 = new Student(1, "Tom", 17);
    Student* stu2 = new Student(2, "Jack", 18);
    swap(stu1, stu2);
    stu1->display();
    stu2->display();
    delete[] stu1;
    delete[] stu2;
    return 0;
}
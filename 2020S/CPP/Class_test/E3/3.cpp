#include <iostream>
#include <cstring>
using namespace std;

class Student
{
private:
    int num;
    string name;
    int age;

public:
    Student(int a, string b, int c) : num(a), name(b), age(c) {}
    ~Student() {}
    void display()
    {
        cout << "num: " << num << endl;
        cout << "name: " << name << endl;
        cout << "age: " << age << endl;
    }
};
int main()
{
    Student *stu1 = new Student(1, "ROCK", 20);
    Student *stu2 = new Student(2, "ROSE", 19);

    swap(stu1, stu2);

    stu1->display();
    cout << endl;
    stu2->display();

    delete stu1;
    delete stu2;
    return 0;
}
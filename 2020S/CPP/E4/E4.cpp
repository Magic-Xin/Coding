#include <bits/stdc++.h>
using namespace std;

class Person
{
private:
    string name;
    int age;
    char sex;

public:
    Person(string a, int b, char c);
    ~Person();
    void display();
};

Person::Person(string a, int b, char c) : name(a), age(b), sex(c)
{
}

Person::~Person()
{
}

void Person::display()
{
    cout << name << " " << age << " " << sex << endl;
}

class Student : public Person
{
private:
    int grade;
    int score;

public:
    Student(string a, int b, char c, int d);
    ~Student() {}
    void show();
    void add(int a);
};

Student::Student(string a, int b, char c, int d) : Person(a, b, c), grade(d)
{
    score = 0;
}

void Student::show()
{
    Person::display();
    cout << grade << " " << score << endl;
}

void Student::add(int a)
{
    score += a;
}

int main()
{
    Student stu1("tom", 18, 'f', 12);
    stu1.add(60);
    stu1.add(120);
    stu1.show();
    return 0;
}
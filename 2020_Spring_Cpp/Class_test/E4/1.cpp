#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
    int age;
    string sex;
    string name;

public:
    Person(string _name, int _age, string _sex) : name(_name), age(_age), sex(_sex) {}
    ~Person() {}
    void display()
    {
        cout << "name: " << name << endl;
        cout << "age: " << age << endl;
        cout << "sex: " << sex << endl;
    }
};

class Student : public Person
{
private:
    int grade;
    int score = 0;

public:
    Student(string _name, int _age, string _sex, int _grade) : Person(_name, _age, _sex), grade(_grade) {}
    ~Student() {}
    void show()
    {
        Person::display();
        cout << "grade: " << grade << endl;
        cout << "score: " << score << endl;
    }
    void add(int _score)
    {
        score += _score;
    }
};

int main()
{
    Student stu1("John", 24, "male", 2);
    stu1.add(85);
    stu1.add(74);
    stu1.show();
    return 0;
}
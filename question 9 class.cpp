#include <iostream>
#include <string>
using namespace std;

// Person class
class Person {
protected:
    string name;

public:
    Person() {
        name = "Unknown";
    }

    Person(string n) {
        name = n;
    }

    virtual void display() {
        cout << "Name: " << name << endl;
    }
};

// Student class, inherited from Person
class Student : public Person {
private:
    string course;
    int marks;
    int year;

public:
    Student(string n, string c, int m, int y) : Person(n) {
        course = c;
        marks = m;
        year = y;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Course: " << course << endl;
        cout << "Marks: " << marks << endl;
        cout << "Year: " << year << endl;
    }
};

// Employee class, inherited from Person
class Employee : public Person {
private:
    string department;
    double salary;

public:
    Employee(string n, string d, double s) : Person(n) {
        department = d;
        salary = s;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
    }
};

// Main function
int main() {
    Person* person1 = new Person("John Doe");
    Person* student1 = new Student("Jane Smith", "Computer Science", 90, 2022);
    Person* employee1 = new Employee("Bob Johnson", "Human Resources", 50000);

    cout << "Displaying Person:" << endl;
    person1->display();

    cout << "Displaying Student:" << endl;
    student1->display();

    cout << "Displaying Employee:" << endl;
    employee1->display();

    delete person1;
    delete student1;
    delete employee1;

    return 0;
}

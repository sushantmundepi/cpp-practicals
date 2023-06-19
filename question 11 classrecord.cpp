#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    int roll_no;
    string name;
    string class_name;
    int year;
    double total_marks;
};

int main() {
    Student students[5];

    // read student data
    for(int i=0; i<5; i++) {
        cout << "Enter data for student " << i+1 << ":\n";
        cout << "Roll No.: ";
        cin >> students[i].roll_no;
        cout << "Name: ";
        cin >> students[i].name;
        cout << "Class: ";
        cin >> students[i].class_name;
        cout << "Year: ";
        cin >> students[i].year;
        cout << "Total Marks: ";
        cin >> students[i].total_marks;
    }

    // write student data to file
    ofstream outfile("students.dat", ios::binary);
    if(!outfile) {
        cerr << "Error: could not open file" << endl;
        return 1;
    }

    for(int i=0; i<5; i++) {
        outfile.write(reinterpret_cast<char*>(&students[i]), sizeof(Student));
    }

    outfile.close();

    // read student data from file
    ifstream infile("students.dat", ios::binary);
    if(!infile) {
        cerr << "Error: could not open file" << endl;
        return 1;
    }

    Student student;

    cout << "\nReading data from file...\n";
    while(infile.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        cout << "Roll No.: " << student.roll_no << endl;
        cout << "Name: " << student.name << endl;
        cout << "Class: " << student.class_name << endl;
        cout << "Year: " << student.year << endl;
        cout << "Total Marks: " << student.total_marks << endl;
        cout << endl;
    }

    infile.close();

    return 0;
}

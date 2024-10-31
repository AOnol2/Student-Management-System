#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    int id;
    string name;
    int age;
    string grade;
    string address;

    void getStudentData() {
        cout << "Enter student ID: ";
        cin >> id;
        cout << "Enter student name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter grade: ";
        cin >> grade;
        cout << "Enter address: ";
        cin.ignore();
        getline(cin, address);
    }

    void displayStudentData() const {
        cout << "ID: " << id << ", Name: " << name << ", Age: " << age 
             << ", Grade: " << grade << ", Address: " << address << endl;
    }
};

void addStudent() {
    Student student;
    student.getStudentData();

    ofstream file("students.txt", ios::app);
    if (file.is_open()) {
        file << student.id << "," << student.name << "," << student.age << ","
             << student.grade << "," << student.address << endl;
        file.close();
        cout << "Student added successfully!\n";
    } else {
        cout << "Error opening file.\n";
    }
}

void displayAllStudents() {
    ifstream file("students.txt");
    if (file.is_open()) {
        string line;
        cout << "All Student Records:\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Error opening file.\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayAllStudents();
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}

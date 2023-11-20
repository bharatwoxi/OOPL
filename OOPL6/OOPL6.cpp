#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class Student {
public:
    int prn;
    string name;
    double math, physics, chemistry, totalPercentage;
    char grade;

    void calculateTotalPercentage() {
        totalPercentage = (math + physics + chemistry) / 3.0;
        calculateGrade();
    }

    void calculateGrade() {
        if (totalPercentage >= 90) {
            grade = 'A';
        } else if (totalPercentage >= 80) {
            grade = 'B';
        } else if (totalPercentage >= 70) {
            grade = 'C';
        } else if (totalPercentage >= 60) {
            grade = 'D';
        } else {
            grade = 'F';
        }
    }
};

class StudentDatabase {
public:
    void addStudentRecord(Student& student) {
        ofstream outFile("students.txt", ios::app);
        if (!outFile) {
            cerr << "Error opening file!" << endl;
            return;
        }

        outFile << student.prn << " " << student.name << " " << student.math << " " << student.physics << " " << student.chemistry << endl;

        outFile.close();
    }

    void displayStudentRecord(int prn) {
        ifstream inFile("students.txt");
        if (!inFile) {
            cerr << "Error opening file!" << endl;
            return;
        }

        int currentPrn;
        string name;
        double math, physics, chemistry;

        while (inFile >> currentPrn >> name >> math >> physics >> chemistry) {
            if (currentPrn == prn) {
                cout << "PRN: " << currentPrn << endl;
                cout << "Name: " << name << endl;
                cout << "Maths: " << math << endl;
                cout << "Physics: " << physics << endl;
                cout << "Chemistry: " << chemistry << endl;
                break;
            }
        }

        inFile.close();
    }

    void modifyStudentRecord(int prn, double math, double physics, double chemistry) {
        ifstream inFile("students.txt");
        ofstream tempFile("temp.txt");

        if (!inFile || !tempFile) {
            cerr << "Error opening file!" << endl;
            return;
        }

        int currentPrn;
        string name;
        double oldMath, oldPhysics, oldChemistry;

        while (inFile >> currentPrn >> name >> oldMath >> oldPhysics >> oldChemistry) {
            if (currentPrn == prn) {
                tempFile << currentPrn << " " << name << " " << math << " " << physics << " " << chemistry << endl;
            } else {
                tempFile << currentPrn << " " << name << " " << oldMath << " " << oldPhysics << " " << oldChemistry << endl;
            }
        }

        inFile.close();
        tempFile.close();

        remove("students.txt");
        rename("temp.txt", "students.txt");
    }

    void deleteStudentRecord(int prn) {
        ifstream inFile("students.txt");
        ofstream tempFile("temp.txt");

        if (!inFile || !tempFile) {
            cerr << "Error opening file!" << endl;
            return;
        }

        int currentPrn;
        string name;
        double math, physics, chemistry;

        while (inFile >> currentPrn >> name >> math >> physics >> chemistry) {
            if (currentPrn != prn) {
                tempFile << currentPrn << " " << name << " " << math << " " << physics << " " << chemistry << endl;
            }
        }

        inFile.close();
        tempFile.close();

        remove("students.txt");
        rename("temp.txt", "students.txt");
    }
};

int main() {
    StudentDatabase database;
    Student student;

    int prn;
    double math, physics, chemistry;

    cout << "Enter PRN: ";
    cin >> student.prn;

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, student.name);

    cout << "Enter Maths marks: ";
    cin >> student.math;
    if (student.math < 0) {
        cerr << "Maths marks cannot be negative!" << endl;
        return 1;
    }

    cout << "Enter Physics marks: ";
    cin >> student.physics;
    if (student.physics < 0) {
        cerr << "Physics marks cannot be negative!" << endl;
        return 1;
    }

    cout << "Enter Chemistry marks: ";
    cin >> student.chemistry;
    if (student.chemistry < 0) {
        cerr << "Chemistry marks cannot be negative!" << endl;
        return 1;
    }

    student.calculateTotalPercentage();

    database.addStudentRecord(student);

    cout << "Student Record Added Successfully!" << endl;

    cout << "\nEnter PRN to search for a student: ";
    cin >> prn;
    database.displayStudentRecord(prn);

    cout << "\nEnter PRN to modify the student record: ";
    cin >> prn;
    cout << "Enter new Maths marks: ";
    cin >> math;
    cout << "Enter new Physics marks: ";
    cin >> physics;
    cout << "Enter new Chemistry marks: ";
    cin >> chemistry;
    database.modifyStudentRecord(prn, math, physics, chemistry);
    cout << "Student Record Modified Successfully!" << endl;

    cout << "\nEnter PRN to delete the student record: ";
    cin >> prn;
    database.deleteStudentRecord(prn);
    cout << "Student Record Deleted Successfully!" << endl;

    return 0;
}

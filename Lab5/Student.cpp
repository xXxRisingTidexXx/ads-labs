#include "Student.h"
#include <iostream>

using namespace std;

Student::Student() {
    cout << "Student" << endl;
    cout << "name: ";
    cin >> name;
    cout << "surname: ";
    cin >> surname;
    cout << "grade: ";
    cin >> grade;
    cout << "isic: ";
    cin >> isic;
    cout << "gender(M/F): ";
    cin >> gender;
    cout << "address: ";
    cin >> address;
}

unsigned short Student::get_grade() {
    return grade;
}

unsigned int Student::get_isic() {
    return isic;
}

char Student::get_gender() {
    return gender;
}

string Student::get_address() {
    return address;
}

ostream &operator<<(ostream &out, Student &student) {
    out << "Student (name = " << student.name << ", surname = " << student.surname <<
    ", grade = " << student.grade << ", isic = " << student.isic << ", gender = " <<
    student.gender << ", address = " << student.address << ")";
    return out;
}

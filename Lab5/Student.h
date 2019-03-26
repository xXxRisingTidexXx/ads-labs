#ifndef LAB5_STUDENT_H
#define LAB5_STUDENT_H

#include <iostream>

using namespace std;

class Student {
private:
    string name;
    string surname;
    unsigned short grade;
    unsigned int isic;
    char gender;
    string address;

public:
    Student();
    unsigned short get_grade();
    unsigned int get_isic();
    char get_gender();
    string get_address();
    friend ostream &operator<<(ostream &, Student &);
};


#endif

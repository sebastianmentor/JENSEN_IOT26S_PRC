#ifndef STUDENT_CLASS_H
#define STUDENT_CLASS_H

#include <string>

class Student
{
public:
    std::string name;
    std::string course;
    int points;
    char grade;

    Student(const std::string& name, const std::string& course);
    ~Student();

    void print();
};

#endif
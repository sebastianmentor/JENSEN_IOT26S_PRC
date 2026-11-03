#include <iostream>
#include "student.h"


Student::Student(const std::string& name, const std::string& course)
    :name(name), course(course){
    points = 0;
    grade = '\0';
}

Student::~Student()
{
    std::cout << "Set student " << name << " free! Enjoy work\n";
}

void Student::print(){
    std::cout << "Student " << name << " takes course " << course << "\n";
    std::cout << "\t" << "Total point " << points << " with a grade " << grade << "\n";
}
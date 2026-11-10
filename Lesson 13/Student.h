#ifndef STUDENT_CLASS_H
#define STUDENT_CLASS_H

#include "User.h"

enum class School{
    Jensen,
    Nackademin,
    Kth,
    Sti
};

class Student: public User
{
private:
    std::string name_;
public:
    Student(std::string name, std::string password, School school);
    ~Student();

    const std::string& get_name() const;
};


#endif
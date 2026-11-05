#ifndef STUDENT_CLASS_H
#define STUDENT_CLASS_H

#include <string>
#include <vector>

class Student
{
private:
    int id_;
    std::string name_;
    std::string password_;
    std::vector<std::string> courses_;

public:
    Student(const std::string& name,const std::string& password);
    ~Student();
    int get_id() const;
    std::string get_name() const;
    bool check_password(const std::string& password) const;
    bool change_password(const std::string& old_password, const std::string& new_password);
    bool add_course(const std::string& new_course);
    void print_courses() const;

};




#endif
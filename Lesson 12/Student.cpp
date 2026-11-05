#include "Student.h"
#include <iostream>

int global_student_id_counter = 1000;

Student::Student(const std::string& name,const  std::string& password)
    :id_(global_student_id_counter), name_(name), password_(password){
        global_student_id_counter ++;
}

Student::~Student(){
    std::cout << "Kick student " << name_ << " out from school\n";
}

int Student::get_id() const{
    return id_;
}

std::string Student::get_name() const{
    return name_;
}

bool Student::check_password(const std::string& password) const{
    return password == password_;
}

bool Student::change_password(const std::string& old_password, const std::string& new_password){
    if(new_password.length() < 4){
        return false;
    }

    if(check_password(old_password)){
        password_ = new_password;
        return true;
    }
    return false;

}


bool Student::add_course(const std::string& new_course){
    std::string new_course_copy = new_course;
    for(auto &x:new_course_copy){
        x=tolower(x);
    }
    std::cout << new_course_copy << "\n";

    for(auto course: courses_){
        for(auto &c:course){
            c = tolower(c);
        }

        if(course == new_course_copy){

            return false;
        }
    }
    courses_.push_back(new_course);
    return true;
}




void Student::print_courses() const{
    std::cout << "Student " << id_ << " takes following courses:\n";
    for(auto course: courses_){
        std::cout << "\t" << course << "\n";
    }
}
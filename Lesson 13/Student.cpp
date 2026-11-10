#include "Student.h"

std::string school_prefix(School school){
    switch (school)
    {
    case School::Jensen:
        return "JEN";
    case School::Nackademin:
        return "NAC";
    case School::Kth:
        return "KTH";
    case School::Sti:
        return "STI";
    default:
        break;
    }
    return "";
}

Student::Student(std::string name, std::string password, School school)
    :User(school_prefix(school) + name, password, UserRole::Student), name_(name){}

Student::~Student()
{
}

const std::string& Student::get_name() const{
    return name_; 
}
#include <iostream>
#include "Student.h"

void print_students(const std::vector<Student>& students){
    for(auto &student: students){
        std::cout << "Student id " << student.get_id() << " with name "<< student.get_name() << "\n";
    }
}

void run_program(){
    // std::vector<Student> students = {
    //     Student("Kalle", "1234"),
    //     Student("Nisse", "qwer"),
    //     Student("Bertil", "asdf")
    //     };

    std::vector<Student> s;
    s.emplace_back(Student("Kalle", "1234"));
    s.emplace_back(Student("Nisse", "qwer"));
    s.emplace_back(Student("Bertil", "asdf"));

    print_students(s);
    // print_students(students);
}

int main(){

    run_program();

    // Student s1("Sebastian", "qwer1234");
    // std::cout << "Student " << s1.get_name() << " has now been created!\n";

    // std::string try_password;
    // std::cout << "Enter password to see if you are worthy\n";
    // std::cin >> try_password;

    // if(s1.check_password(try_password)){
    //     std::cout << "You are worthy my friend! You may pass\n";

    //     for(int i = 1; i < 6; i++){
    //         std::string new_course;
    //         std::cout << "Enter course " << i << "\n";
    //         std::cin >> new_course;
    //         if(s1.add_course(new_course)){
    //             std::cout << "Course " << new_course << " added to courses\n";
    //         }
    //         else{
    //             std::cout << "Course already taken\n";
    //         }
    //     }
    // }
    // else{
    //     std::cout << "Totaly wrong man, get the hell out of here!\n";
    // }

    // s1.print_courses();

    // std::cout << "Enter old password: ";
    // std::cin >> try_password;
    // std::cout << "Enter new password: ";
    // std::string new_password;
    // std::cin >> new_password;

    // if(s1.change_password(try_password, new_password)){
    //     std::cout << "New password set!\n";
    // }
    // else{
    //     std::cout << "Could not set new password!\n";
    // }

    return 0;
}
#include <iostream>
#include "User.h"
#include "Student.h"

int main(){
    // UserRole master = UserRole::Admin;

    // User new_user("SEB1337", "Secret", UserRole::Admin);

    // if(new_user.get_role()==master){
    //     std::cout << new_user.get_username() <<" has access now!\n";
    // }
    // std::string pw;
    // std::cout << "Enter password:";
    // std::cin >> pw;

    // if(new_user.authorize(pw)){
    //     std::cout << "You are now logged in!\n";
    // }

    Student new_student("Sebastian","qwer1234", School::Jensen);

    std::cout << "new_student with name " << new_student.get_name();
    std::cout << " and username " << new_student.get_username() << "\n";


    
}
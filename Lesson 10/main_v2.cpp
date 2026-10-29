#include <iostream>
#include <string>

void inc_age(int& kalle){ 
    kalle = kalle + 1;
    // age += 1
    // age ++;
}

int main() {
    int age = 42;
    inc_age(age);
    std::cout << "age is now " << age << "\n";
    int& user_age = age;
    inc_age(user_age); 
    std::cout << "age is now " << age << "\n";

    int user_input;
    std::cout << "Enter a number:";
    std::cin >> user_input;
    user_age = user_input; // age = user_input;
    std::cout << "age is now " << age << "\n";



    return 0;
}
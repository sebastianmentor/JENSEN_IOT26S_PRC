#include <iostream>

int main() {
    int age = 42;
    float pi = 3.1415;

    std::cout << "Hello from C++!\n";
    std::cout << "age = " << age << "\n";
    std::cout << "Pi  = " << pi  << "\n";
    std::cout << "Enter new age:";
    std::cin  >> age;
    std::cout << "You enter age " << age << std::endl;
    std::cout << "Enter new pi:";
    std::cin >> pi;
    std::cout << "You enter " << pi << "\n";

    return 0;
}
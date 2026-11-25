#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void print_numbers(const int *numbers, int size){
    for(int i = 0; i < size; i++){
        std::cout << "Value of numbers: " << numbers[i] << "\n";
    }
}

void print_numbers_better(const std::vector<int> &numbers){
    for(const auto &n:numbers){
        std::cout << "Number " << n << "\n";
    }
}

int main(){
    std::cout << "Must use std::cout to print instead of printf()\n";
    int some_number = 0;
    std::cin >> some_number;

    if(some_number > 10){
        for(int i = 0; i<5; i++){
            std::cout << "Row " << i + 1 << std::endl;
        }
    }

    int numbers[5] = {1,2,3,4, some_number};

    for(int &n: numbers){
        n = n+1;
        std::cout << "Change n to " << n << "\n";
    }

    // // for(int n: numbers)
    // for(int i = 0; i < 5; i++){
    //     int n = numbers[i];
    // }

    // // for(int &n: numbers)
    // for(int i = 0; i < 5; i++){
    //     int *n = &numbers[i];
    // }

    print_numbers(numbers, sizeof(numbers)/sizeof(numbers[0]));

    char text[] = "My super text!"; // still valid but dangerus

    std::string text2 = "My super text! 1337";

    for(auto &c:text2){
        c = toupper(c);
    }

    std::cout << "text is "<< text << "\ntext2 is " << text2 << "\n";

    std::vector<int> numbers2 = {1,2,3,4, some_number};

    print_numbers_better(numbers2);

    for(auto i = numbers2.end() - 1; i > numbers2.begin() - 1; i--){
        std::cout << "Numbers " << *i << "\n";
    }

    reverse(numbers2.begin(), numbers2.end());

    print_numbers_better(numbers2);

}
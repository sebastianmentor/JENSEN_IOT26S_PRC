#include <iostream>
#include "student.h"


Student *create_student(){
    std::string new_name;
    std::string course;
    int points = -1;
    
    std::cout << "Enter name on student: ";
    std::cin >> new_name;

    std::cout << "Enter course name: ";
    std::cin >> course;

    Student *s = new Student(new_name, course);

    while (points < 0 || points > 100)
    {
        std::cout << "Enter points between 0 and 100: ";
        std::cin >> points;
    }

    s -> points = points;

    return s;

}

void grade_student(Student& s){
    int normalized_points = s.points / 10;
    switch (normalized_points)
    {
    case 10:
        s.grade = 'A';
        break;
    case 9:
        s.grade = 'A';
        break;
    case 8:
        s.grade = 'B';
        break;   
    case 7:
        s.grade = 'C';
        break;
    case 6:
        s.grade = 'D';
        break;
    case 5:
        s.grade = 'E';
        break;                  
    default:
        s.grade = 'F';
        break;
    }
}

void run_program(Student **students, int max_students){
    int total_students = 0;
    while (true)
    {
        std::cout << "1. Add new student\n";
        std::cout << "2. Print all student\n";
        std::cout << "3. Grade student\n";
        std::cout << "0. Exit\n";

        int user_input;
        std::cout << "Enter choice: ";
        std::cin >> user_input;

        if(user_input == 1){
            if(total_students == max_students){
                std::cout << "Maximum students! Cant add more students\n";
                continue;
            }

            students[total_students] = create_student();
            total_students++;

            std::cout << "Remember to grade student!\n";

        }
        else if(user_input == 2){
            for(int i = 0; i < total_students; i++){
                students[i] -> print();
            }
        }
        else if(user_input == 3){
            std::string student_name;
            std::cout << "Enter students name: ";
            std::cin >> student_name;

            bool student_found = false;

            for(int i = 0; i < total_students; i++){
                if(students[i] -> name == student_name){
                    grade_student(*students[i]);
                    student_found = true;
                    break;
                }
            }

            if(student_found){
                std::cout << "Grade updated!\n";
            }
            else{
                std::cout << "Could not find student with name "<<student_name <<"\n";
            }
        }
        else if(user_input == 0){
            std::cout << "Start cleaning upp\n";

            for(int i = 0; i < total_students; i++){
                delete students[i];
            }

            std::cout << "Cleaning done! Good bye!\n";

            break;
        }
        else{
            std::cout << "Invalid choice!\n";
        }

    }
    
}

int main(){

    Student *students[10];
    run_program(students, 10);

}
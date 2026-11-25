#include "Furniture.h"
#include <cassert>


Furniture::Furniture(std::string color, 
        std::string material,
        int number_of_legs)
    :color_(color), material_(material),number_of_legs_(number_of_legs){}


Soffa::Soffa(
        std::string color, 
        std::string material,
        int number_of_legs,
        int butt_number)

    : Furniture(color,material,number_of_legs),
      butt_number_(butt_number),
      number_of_butts_on_soffa_(0){}


bool Soffa::sit_on_soffa(){
    if(number_of_butts_on_soffa_ < butt_number_){
        number_of_butts_on_soffa_++;
        return true;
    }
    return false;
}

void Soffa::leave_soffa(){
    if(butt_number_ > 0){
        butt_number_--;
    }
}

Armchair::Armchair(
        std::string color, 
        std::string material,
        int number_of_legs)

     :Furniture(color,material,number_of_legs),
      someone_sit(false){}

bool Armchair::sit(){
    if(someone_sit){
        return false;
    }
    someone_sit = true;
    return true;
}      

bool Armchair::leave(){
    if(someone_sit){
        someone_sit = false; 
        return true;
    }
    return false;
}


// Test
void test_Armchari_sit_twice(){
    Armchair a("","",4);
    assert(a.sit()==true);
    assert(a.sit()==false);
}

void test_Armchari_leave_before_sit(){
    Armchair a("","",4);
    assert(a.leave()==false);
}

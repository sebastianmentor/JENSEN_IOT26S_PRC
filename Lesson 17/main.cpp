#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Furniture.h"

class Power
{
private:
    int watt_;
public:
    Power(int watt){
        watt_ = (watt<0)?0:watt;
    }
    int get_watt() const {return watt_;}
};

class Lamp
{
private:
    const Power power_rating_;
    bool is_on_;
public:
    Lamp(Power pr):power_rating_(pr),is_on_(false){}
    void turn_on(){is_on_ = true;}
    void turn_off(){is_on_ = false;}
    void light() const{
         if(is_on_ == true && (power_rating_.get_watt() > 0)){
            std::cout << "Lights upp the room\n";
         }
         else{
            std::cout << "Darkness is here!\n";
         }
    }
    int get_power_rating(){
        return power_rating_.get_watt();
    }
};

class Room
{
private:
    std::string location_;
    std::vector<Lamp> lamps_;
public:
    Room(std::string location):location_(location){};
    Room(std::string location, const std::vector<Lamp> &lamps)
        :location_(location),lamps_(lamps){};
    void add_lamp(const Lamp& new_lamp){
        lamps_.push_back(new_lamp);
    }
    void is_room_lit(){
        for(auto &l:lamps_){
            l.light();
        }
    }
};


int main()
{   
    Power forty_watt(40);
    Power ten_watt(10);
    Power hundred_watt(100);
    Power negative_ten_watt(-10);
    
    std::cout << "Power values: \n";
    std::cout << forty_watt.get_watt() << "\n";    
    std::cout << ten_watt.get_watt() << "\n";    
    std::cout << hundred_watt.get_watt() << "\n";    
    std::cout << negative_ten_watt.get_watt() << "\n";

    //Create lamps

    Lamp lamp1(forty_watt);
    Lamp lamp2(ten_watt);
    Lamp lamp3(hundred_watt);
    Lamp lamp4(negative_ten_watt);

    std::vector<Lamp*> all_lamps = {&lamp1, &lamp2, &lamp3, &lamp4};

    lamp2.turn_on();
    lamp4.turn_on();

    for(auto l:all_lamps){
        l->light();
    }

    Room living_room("Living room");
    living_room.add_lamp(lamp1);
    living_room.add_lamp(lamp2);
    
    lamp2.turn_off();
    std::cout << "\n\n";
    living_room.is_room_lit();

    // Furniture

    //first test
    test_Armchari_leave_before_sit();
    test_Armchari_sit_twice();
    std::cout << "All test succeded!\n";


    Armchair chair1("Brown", "Wood", 4);
    Armchair chari2("White", "Metal", 3);

    Soffa soffa1("Pink", "Cotton", 8, 6);
    Soffa soffa2("Black", "Silk", 10, 8);

    char user_input;
    std::cout << "Do you want to sit on armchair 1?(y/n)\n";
    std::cin >> user_input;

    if(user_input == 'y'){
        chair1.sit();
    }

    std::cout << "Do secont persone want to sit on armchair 1?(y/n)\n";
    std::cin >> user_input;    
    if(user_input == 'y'){
        if(!chair1.sit()){
            std::cout << "Sorry, the person before is sitting in the chair already!\n";
        }
    }

    for(int i = 1; i < 12; i++){
        std::cout << "Person number " << i << " will try sit on soffa!\n";
        if(!soffa1.sit_on_soffa()){
            std::cout << "Sorry person " << i << ", the soffa is full!\n";
        }
        else{
            std::cout << "Sit your ass down now!\n";
        }
    }
}
#ifndef FURNITURE_CLASS_H
#define FURNITURE_CLASS_H

#include <string>


class Furniture
{
protected:
    const std::string color_;
    const std::string material_;
    int number_of_legs_;
public:
    Furniture(
        std::string color, 
        std::string material_,
        int number_of_legs);
};

// all furnitures

class Soffa: public Furniture
{   
private:
    int butt_number_;
    int number_of_butts_on_soffa_;

public:
    Soffa(std::string color, 
        std::string material,
        int number_of_legs,
        int butt_number);

    bool sit_on_soffa();
    void leave_soffa();
};

class Armchair: public Furniture
{
private:
    bool someone_sit;
public:
    Armchair(std::string color, 
        std::string material,
        int number_of_legs);

    bool sit();
    bool leave();
};

//

void test_Armchari_sit_twice();
void test_Armchari_leave_before_sit();

#endif
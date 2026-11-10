#include <iostream>
#include <string>

int global_Sensor_id_increment = 1000;

class base
{
protected:
    int base_value_;
public:
    base():base_value_(-1){}
    base(int bv):base_value_(bv){}
};

class derived: public base
{
private:
    int derived_value_;
public:
    derived(int dv):derived_value_(dv){};
    derived(int dv, int bv):base(bv), derived_value_(dv){}

    void set_base_value(int bv){
        base_value_ = bv;
    }

    void print(){
        std::cout << "Base value " << base_value_ << " and derived value " << derived_value_ << "\n";
    }
};

class derived_derived: public derived{
private:
    int dd_value;
public:
    derived_derived(/* args */);
    ~derived_derived();
};



class Sensor{
protected:
    int id_;
    std::string location_;
    std::string type_;

    void print_from_derived_class(){
        std::cout << "This method can only be called by a derived class!\n";
    }
public:

    Sensor(std::string type):id_(global_Sensor_id_increment), type_(type){
        global_Sensor_id_increment++;    
    }
    void set_location(std::string location){
        location_ = location;
    }

    void print(){
        std::cout << "Sensor "<< id_ << " is located at " << location_ << " and is of type " << type_ << "\n";
    }
};

class TemperatureSensor: public Sensor{
private:
    double temperature_;
public:
    TemperatureSensor():Sensor("Temperatur"), temperature_(0){}
    TemperatureSensor(double value):Sensor("Temperatur"), temperature_(value){}

    double get_temperature(){
        return temperature_;
    }

    void print(){
        std::cout << "Temperature sensor " << id_ << " has temperature " << temperature_ << "\n";
        print_from_derived_class();
    }
};

class HumiditySensor: public Sensor{
private:
    int humidity_;
public:
    HumiditySensor():Sensor("Humidity"), humidity_(0){}
    HumiditySensor(int humidity):Sensor("Humidity"){
        if(humidity < 0){humidity_=0;}
        else if(humidity > 100){humidity_=100;}
        else{humidity_ = humidity;}
    }

    double get_humidity(){
        return humidity_;
    }
};

class MotionDetectionSensor: public Sensor
{
private:
    bool motion_detected_;
public:
    MotionDetectionSensor():Sensor("Motion Detection"), motion_detected_(false){};
};

int main(){
    Sensor s1("Power");
    s1.set_location("Kitchen");
    s1.print();

    TemperatureSensor t1(23.2);
    t1.set_location("Outdoor");
    t1.print();

    HumiditySensor h1(45);
    h1.set_location("Living room");
    h1.print();

    derived d(5);
    d.print();
    d.set_base_value(10);
    d.print();

    derived d2(12, 66);
    d2.print();

    MotionDetectionSensor md1;

    TemperatureSensor *t1_ptr = &t1;
    // t1_ptr->print();
    Sensor s_ref = t1;
    s_ref.print();

    std::cout << "Inför nästa lektion\n";
    // fundering inför nästa lektion!
    Sensor *sensors[3] = {&t1, &h1, &md1};

    for(auto &s: sensors){
        s->print();
    }
}
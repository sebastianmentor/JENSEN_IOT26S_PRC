#include <iostream>
#include <string>

typedef struct
{
    int time;
    double value;
}TimeStamp;

class SensorType{
    public:
        std::string sensor_type;
};


class Sensor {
    public:
        int id;
        double value;
        TimeStamp t;
        SensorType type;

        void print_me(){
            std::cout << "Sensor " << id << " has value " << value << std::endl;
            std::cout << "type " << type.sensor_type << "\n";
            std::cout << "timestamp " << t.time << " " << t.value << "\n";

        }
};

int main() {
    Sensor s1;
    s1.id = 1;
    s1.value = 21.5;
    // std::cout << s1.value << "\n";
    s1.print_me();

    Sensor s3;
    s3.id = 2;
    s3.value = 25.5;
    // std::cout << s3.value << "\n";    
    s3.print_me();
    
    Sensor new_sensor;
    new_sensor.id = 4;
    new_sensor.value = 44.1;
    new_sensor.type.sensor_type = "Temperature";
    new_sensor.t.time = 12;
    new_sensor.t.value = 39.8;
    
    new_sensor.print_me();

    return 0;
 }
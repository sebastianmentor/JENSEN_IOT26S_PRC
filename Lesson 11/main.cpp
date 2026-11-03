#include <iostream>
#include <string>

int sensor_id_count = 1;

class Sensor {
    public:
    int id;
    double value;

    Sensor(int id, double start_value){
        // print value of id and value  
        this -> id = id;
        value = start_value; 
    }

    Sensor(){
        value = 0.0;
        id = sensor_id_count;
        sensor_id_count++;
    }    

    void print(){
        std::cout << id << " " << value << "\n";
    }
};

typedef enum{
    ESP32 = 1,
    ARDUINO,
    STM32,
}MCUBrand;

class MCU{
    public:
    std::string name;
    MCUBrand brand;

    MCU(std::string &name, MCUBrand brand)
        : name(name), brand(brand){
            std::cout << "We are now creating MCU " << name << " wiht brand" << brand << "\n"; 
        }
    
    ~MCU(){
        std::cout << "Lets end this MCU! Oveload it with 100V\nWe now have magic smoke!!\n";
    }

    void print(){
        std::cout << brand << " " << name << "\n";
    }
    
};

class Buffert {
    public:
        int *data;

        Buffert(int storlek) {
            std::cout << "Allocate an int array of size " << storlek << "\n";
            data = new int[storlek];
        }

        ~Buffert() {
            std::cout << "Free an int array\n";
            delete[] data;
        }
};

void create_MCU(std::string& mcu_name, MCUBrand mcu_brand){
    std::cout << "Starting create_MCU\n";
    MCU local_MCU(mcu_name, mcu_brand);
    local_MCU.print();
    std::cout << "We have now created mcu and are leaving the create_MCU\n";
}

void create_buff(int size){
    std::cout << "Starting create_buff\n";
    Buffert local_buff(size);
    std::cout << "Working with buffer\nWe are now done!\n";
    
}

int main() {
    Sensor s1;
    // std::cout << s1.value << "\n";
    s1.print();

    Sensor s2(123, 2.2);
    // std::cout << s2.value << "\n";
    s2.print();
    std::string name = "UNO 3";
    create_MCU(name, ARDUINO);

    Buffert my_buff(10);
    create_buff(100);


    Sensor *my_sensors[10];


    std::cout << "Exit program now!\n";


    return 0;
 }
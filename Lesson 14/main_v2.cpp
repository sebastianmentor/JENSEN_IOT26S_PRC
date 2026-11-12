#include <iostream>

int sensor_id_counter = 1000;

class Sensor {
    protected:
        int id_;
    public: 
        Sensor():id_(sensor_id_counter){sensor_id_counter++;}
        virtual void skriv_ut() const { std::cout << "Sensor " << id_ << "\n"; }
        void change_id(int id){id_ = id;}
};

class TemperaturSensor : public Sensor {
    private:
        int temperature;
    public: 
        void skriv_ut() const override{ std::cout << "Temperatursensor " << id_ << "\n"; }
};

class FuktSensor : public Sensor {
    public: 
        void skriv_ut() const  override{ std::cout << "Fuktsensor " << id_ << "\n"; }
};

class VibrationSensor : public Sensor {
    public: 
        void larma() { std::cout << "Vibrationslarm\n"; }
};

void visa(const Sensor &s){
    s.skriv_ut();
}


int main() {
    TemperaturSensor t1;
    FuktSensor f1;
    VibrationSensor v1;

    Sensor s_arr[3] = {t1, f1, v1};
    Sensor* s_arr_ptr[3] = {&t1, &f1, &v1};
    std::cout << "-----------------\n";
    for(auto sensor: s_arr_ptr){
        visa(*sensor);
    }
    std::cout << "-----------------\n";
    for(auto sensor: s_arr){
        visa(sensor);
    }

    t1.change_id(2000);
    f1.change_id(3000);
    v1.change_id(4000);
    std::cout << "-----------------\n";
    // s_arr[0].change_id(9999);
    for(auto sensor: s_arr_ptr){
        visa(*sensor);
    }
    std::cout << "-----------------\n";
    for(auto sensor: s_arr){
        visa(sensor);
    }

    return 0;
}
#include <iostream>

int sensor_id_counter = 1000;

class Sensor {
    protected:
        int id_;
    public: 
        Sensor():id_(sensor_id_counter){sensor_id_counter++;}
        virtual void skriv_ut() const = 0; // Måste implementeras av alla klasser som ärver av Sensor!
        void change_id(int id){id_ = id;}
        virtual ~Sensor(){std::cout << "Base Sensor " << id_ << " is now destroyd\n";}
};

class TemperaturSensor : public Sensor {
    private:
        int temperature_;
    public: 
        TemperaturSensor(int temp):temperature_(temp){};
        void skriv_ut() const override{ 
            std::cout << "Temperatursensor " << id_ << "\n"
            << "Temperature is " << ((temperature_ < 17)? "cold":"varm") 
            <<" today\n"; }

        ~TemperaturSensor(){std::cout << "Bye bye temperature sensor "<< id_ << "\n";}
};

class FuktSensor : public Sensor {
    private:
        int humidity_;
    public: 
        FuktSensor(int humidity){
            if(humidity < 0){
                humidity_ = 0;
            }
            else if(humidity > 100){
                humidity_ = 100;
            }
            else{
                humidity_ = humidity;
            }
        }
        void skriv_ut() const  override{ 
            std::cout << "Fuktsensor " << id_ << " has humidity " << humidity_ << "\n"; }
};

class VibrationSensor : public Sensor {
    private:
        bool vibrate_;
    public: 
        VibrationSensor(bool vibrate):vibrate_(vibrate){}
        void larma() { std::cout << "Vibrationslarm\n"; }
        void skriv_ut() const override{ 
            std::cout << "Vibrationssensor " << id_ << "\n"
            << "The world is "<< ((vibrate_?"vibrating":"not virating")) << "\n";}
};

class LjudSensor: public Sensor
{
private:
    /* data */
public:
    virtual void skriv_ut() const{
        std::cout << "asdasdffadsafsdafsdafsdfasd\n";
    }
};


void visa(const Sensor &s){
    s.skriv_ut();
}

void visa_alla(Sensor **s_ptr, size_t size){
    for(size_t i = 0; i < size; i++){
        visa(*s_ptr[i]);
    }
}


int main() {
    LjudSensor l1;
    TemperaturSensor t1(22);
    FuktSensor f1(23);
    VibrationSensor v1(true);
    Sensor *t2 = new TemperaturSensor(15);
    FuktSensor f2(121);
    VibrationSensor v2(false);
    // Sensor s1;

    // Sensor s_arr[3] = {t1, f1, v1};
    Sensor* s_arr_ptr[6] = {&t1, &f1, &v1, t2, &f2, &v2};

    visa_alla(s_arr_ptr, 6);

    delete t2;

    return 0;
}
#include <iostream>

class Sensor {
    public: 
        virtual void skriv_ut() const { std::cout << "Sensor\n"; }
};

class TemperaturSensor : public Sensor {
    public: 
        void skriv_ut() const override{ std::cout << "Temperatursensor\n"; }
};

class FuktSensor : public Sensor {
    public: 
        void skriv_ut() const  override{ std::cout << "Fuktsensor\n"; }
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
    t1.skriv_ut();
    Sensor* s = &t1;
    s->skriv_ut();
    std::cout << "Try visa\n";
    visa(*s);
    visa(t1);
    FuktSensor f1;
    s = &f1;
    s->skriv_ut();
    visa(f1);
    
    VibrationSensor v1;
    v1.larma();
    s = &v1;
    s->skriv_ut();
    visa(v1);



    return 0;
}
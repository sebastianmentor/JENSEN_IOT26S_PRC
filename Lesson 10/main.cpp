#include <iostream>

class Sensor {
    public:
    
    int id = 0;
    double value = 0.0;

    void print() const{
        std::cout << "Sensor" << id << ": " << value << "\n";
    }

    void update_id(int new_id){
        id = new_id;
    }

};

int main() {
    Sensor sensors[10];
    for(int i = 0; i < 10; i++){
        sensors[i].id = i+1;
        sensors[i].value = 19.0+i;
    }

    for(int i = 0; i < 10; i++){
        sensors[i].print();
    }



    return 0;
}
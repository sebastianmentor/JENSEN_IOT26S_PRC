#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <ctime>



class Sensor{
private:
    double value_;
    int id_;
public:
    Sensor(int id):id_(id){
        double lower = 0, upper = 90;
        double random_double = lower
            + (upper - lower) * rand() / RAND_MAX;
        value_ = random_double;
    
    }

    int get_id() const {return id_;}
    double get_value() const {return value_;}
    double read_value(){
        double noise = rand();
        return value_ + noise;}
};

void print_sensors(const std::vector<Sensor>& sensors){
    for(auto &s:sensors){
    std::cout << "Sensor " << s.get_id() 
                << " has value "<< s.get_value()
                <<"\n";     
            }
}

bool compare_sensors_value_gt(const Sensor& s1, const Sensor& s2){
    // acending
    return s1.get_value() < s2.get_value();
}

bool compare_sensors_value_lt(const Sensor& s1, const Sensor& s2){
    // decending
    return s1.get_value() > s2.get_value();
}

int main(){
    srand(time(0));

    std::vector<Sensor> our_sensors;
    std::vector<int> our_ints;

    for(int i = 1; i < 11; i++){
        our_sensors.push_back(Sensor(i));
        // std::cout << our_sensors.capacity() << "\n";
    }

    print_sensors(our_sensors);

    std::sort(our_sensors.begin(), our_sensors.end(), compare_sensors_value_gt);
    std::cout << "####################\n";
    print_sensors(our_sensors);
    
    std::sort(our_sensors.begin(), our_sensors.end(), compare_sensors_value_lt);
    std::cout << "####################\n";
    print_sensors(our_sensors);

    std::map<std::string, int> student_score;
    student_score["Sebastian"] = 88;
    student_score["Nils"] = 38;
    student_score["Eva"] = 41;
    student_score["Adam"] = 100;

    for(auto &sc: student_score){
        std::cout << "Student " << sc.first << " has score " << sc.second << "\n"; 
    }

    std::map<int, int> m;
    m[23] = 8;
    m[1] = 5;
    m[5] = 9;
    m[9] = 7;

    for(auto &mm: m){
        std::cout << mm.first << " " <<mm.second << "\n";
    }

}
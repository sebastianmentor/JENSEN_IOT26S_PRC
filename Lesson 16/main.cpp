#include <iostream>
#include <cassert>
#include <vector>

double medelvarde(const std::vector<int>& varden) {
    // assert(varden.size() != 0);
    if(varden.size() == 0) return 0.0;
    int summa = 0;
    for (int v : varden) summa += v;
    return (double)summa / varden.size();
}

void test_medelvarde_empty_vector(){
    std::vector<int> empty = {};
    assert(medelvarde(empty) == 0);
}

void test_medevarde_valid_data(){
    std::vector<int> even_medevarde = {1,2,3,4,5};
    assert(medelvarde(even_medevarde) == 3.0);
    std::vector<int> decimal_medevarde = {1,2,3,4,5,6};
    assert(medelvarde(decimal_medevarde) == 3.5);
}

int some_function(int v, int &r){
    int b;
    int y = 10;
    b = v;
    if(b == y){
        r = 3;
    }
    return y - v;
}

int main() {
    int summa = 2 + 2;
    assert(summa == 4);
    test_medelvarde_empty_vector();
    test_medevarde_valid_data();
    std::cout << "Testet lyckades\n";
    std::vector<int> tom;
    std::cout << "tom.size() = " << tom.size() << "\n";
    std::cout << "Lets go, medelvarde(tom)\n";
    std::cout << medelvarde(tom) << "\n";
    std::cout << medelvarde(tom) + 1.1 << "\n";

    int my_int = 4;
    int my_int2 = 5;
    my_int = some_function(4, my_int2);

    std::cout << my_int;
    return 0;
}
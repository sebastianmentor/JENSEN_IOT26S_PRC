#include <iostream>
#include <vector>

int main() {
    // int j = 4;
    // int i = 5;

    // int new_int = j++ + ++i;

    // /*
    // i += 1;
    // new_int = j + i;
    // j += 1;
    // */
    // int v = 10;
    // int new_new_int = v++ + ++v; //?

    std::cout << "Starting program!\n";
    std::vector<int> number = {1, 2, 3, 4, 5, 6};
    
    for (auto it = number.begin(); it != number.end();) {
        if (*it % 2 == 0) {
            it = number.erase(it);
        }else{
            ++it;
        }

        
    }

    for (int t : number) {
        std::cout << t << " ";
    }
    std::cout << "\n";

    return 0;
}
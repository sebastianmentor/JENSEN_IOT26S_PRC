#include <iostream>

int counter = 1000;

class A
{
protected:
    int id_;
public:
    A():id_(counter){counter++; std::cout << "Create A with id "<< id_ << "\n";}
    virtual void print_id(){std::cout << "A has ID:" << id_ <<"\n";}
};

class B: public A
{
private:
    int b_id_;
public:
    B(int id):b_id_(id){ std::cout << "Create B\n";};
    void print_id(){
        std::cout << "B has ID:" << b_id_ <<"\n"
                  << "And id_ has value " << id_ << "\n";}
};


int main() {
    A my_a;
    B my_b(12);

    my_a.print_id();
    my_b.print_id();

    A *ptr = &my_a;
    ptr->print_id();
    ptr = &my_b;
    ptr->print_id();


    return 0;
}
#include <iostream>
using namespace std;
// #include "ComplexNumbers.h"


class ComplexNumbers {
    // Complete this class
    public:
    int real,imaginary;

    ComplexNumbers(int r,int i){
        real =r ; 
        imaginary=i ; 
    }

    void plus(ComplexNumbers s){
        this->real = this->real + s.real;
        this->imaginary = this->imaginary + s.imaginary;
    }

    void multiply(ComplexNumbers s){
        //(a + ib)(c + id) = (ac - bd) + i(ad + bc)
        int a = this->real;
        int b = this->imaginary;
        this->real = (a * s.real) - (b * s.imaginary);
        this->imaginary = (a * s.imaginary) + (b * s.real);
    }

    void print(){
        cout << real <<" + i"<< imaginary << endl;
    }
};

int main() {
    int real1, imaginary1, real2, imaginary2;
    
    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;
    
    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);
    
    int choice;
    cin >> choice;
    
    if(choice == 1) {
        c1.plus(c2);
        c1.print();
    }
    else if(choice == 2) {
        c1.multiply(c2);
        c1.print();
    }
    else {
        return 0;
    }   
}
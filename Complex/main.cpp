#include "classes/Complex.cpp"

int main(){
    Complex c = Complex(3,3);
    Complex c1 = Complex(-1, 2);

    Complex c2 = c1 - c;

    c2.print();

    return 0;
}
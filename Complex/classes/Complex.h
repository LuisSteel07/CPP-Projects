#include <iostream>
using namespace std;

class Complex{
    private:
        float real;
        float imaginary;
    public:
        Complex(float, float);
        float GetReal();
        float GetImaginary();
        void SetReal(float);
        void SetImaginary(float);
        void print();
        Complex Conjugate();
        Complex operator+(Complex c); 
        Complex operator-(Complex c); 
        Complex operator*(Complex c); 
        Complex operator/(Complex c); 
};
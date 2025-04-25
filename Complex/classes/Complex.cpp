#include "./Complex.h"

Complex::Complex(float _real, float _imaginary){
    this->real = _real;
    this->imaginary = _imaginary;
}

float Complex::GetReal(){
    return this->real;
}

float Complex::GetImaginary(){
    return this->imaginary;
}

void Complex::SetReal(float newReal){
    this->real = newReal;
}

void Complex::SetImaginary(float newImaginary){
    this->imaginary = newImaginary;
}

Complex Complex::Conjugate(){
    return Complex(this->GetReal(), this->GetImaginary()* -1);
}

void Complex::print(){
    if(this->GetImaginary() == 0){
        cout << this->GetReal() << endl;
    }
    else if( this->GetImaginary() == 1 ){
        cout << this->GetReal() << "+" << "i" << endl;
    }
    else if( this->GetImaginary() == -1 ){
        cout << this->GetReal() << "-" << "i" << endl;
    }
    else if(this->GetImaginary() > 0){
        cout << this->GetReal() << "+" << this->GetImaginary() << "i" << endl;
    }
    else if(this->GetImaginary() < 0){
        cout << this->GetReal() << this->GetImaginary() << "i" << endl;
    }
}

Complex Complex::operator+(Complex c){
    float real = this->GetReal() + c.GetReal();
    float imaginary = this->GetImaginary() + c.GetImaginary();
    
    return Complex(real, imaginary);
}

Complex Complex::operator-(Complex c){
    float real = this->GetReal() - c.GetReal();
    float imaginary = this->GetImaginary() - c.GetImaginary();
    
    return Complex(real, imaginary);
}

Complex Complex::operator*(Complex c){
    float real = this->GetReal() * c.GetReal() + (c.GetImaginary() * this->GetImaginary()) * -1;
    float imaginary = this->GetReal() * c.GetImaginary() + this->GetImaginary() * c.GetReal();
    
    return Complex(real, imaginary);
}

Complex Complex::operator/(Complex c){
    Complex numm = *this * c.Conjugate();
    Complex denom = c * c.Conjugate();

    numm.print();
    denom.print();
    
    float real = numm.GetReal()/denom.GetReal();
    float imaginary = numm.GetImaginary() / denom.GetReal();

    return Complex(real, imaginary);
}
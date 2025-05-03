#include "./Fraction.h"
#include <sstream>

Fraction::Fraction(int _num, int _denom){
    this->num = _num;
    this->denom = _denom;
    this->fraction = this->Simplified(_num, _denom); 
}

int Fraction::GetNum(){
    return this->num;
}

int Fraction::GetDenom(){
    return this->denom;
}

string Fraction::GetFraction(){
    return this->fraction;
}

string Fraction::Simplified(int _num, int _denom){
    string fraction = "";

    if(_num == _denom){
        fraction = "1";
    } 
    else if((_num*-1) == _denom){
        fraction = "-1";
    } 
    else if((_num == 0) || (_denom == 0)){
        fraction = "0";
    }
    else {
        int i = 2;
        while(true){
            if((_num % i == 0) && (_denom % i == 0)){
                _num /= i;
                _denom /= i;
            } else break;
            i++;
        }

        string fractione = "";
        
        stringstream stream;
        stringstream stream1;
        
        string Num = "";
        string Denom = "";

        stream << _num;
        stream >> Num;

        stream1 << _denom;
        stream1 >> Denom;

        fraction = Num + "/" + Denom;
    }

    return fraction;
}

Fraction Fraction::operator+(Fraction f){
    int num = (this->num * f.GetDenom()) + (this->denom * f.GetNum());
    int denom = this->denom * f.GetDenom();

    return Fraction(num, denom);
}

Fraction Fraction::operator-(Fraction f){
    int num = (this->num * f.GetDenom()) - (this->denom * f.GetNum());
    int denom = this->denom * f.GetDenom();

    return Fraction(num, denom);
}

Fraction Fraction::operator*(Fraction f){
    int num = this->num * f.GetNum();
    int denom = this->denom * f.GetDenom();

    return Fraction(num, denom);
}

Fraction Fraction::operator/(Fraction f){
    int num = this->num * f.GetDenom();
    int denom = this->denom * f.GetNum();

    return Fraction(num, denom);
}
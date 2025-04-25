#include "../Libraries.h"

class Fraction{
    private:
        int num;
        int denom;
        string fraction;
    public:
        Fraction(int, int);
        int GetNum();
        int GetDenom();
        string Simplified(int, int);
        string GetFraction();
        Fraction operator+(Fraction f);
        Fraction operator-(Fraction f);
        Fraction operator*(Fraction f);
        Fraction operator/(Fraction f);
};
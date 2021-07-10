#include <iostream>
#include "Fraction.h"

int gcd(int a, int b){
    a = abs(a); b = abs(b);
    if(b > a){
        a = a + b;
        b = a - b;
        a = a - b;  
    }
    if(b == 0) return a;
    return gcd(b, a % b);
}

// default constructor
Fraction::Fraction() :
    m_numerator(1), m_denominator(1) {}

// generic constructor1
Fraction::Fraction(int num, int den):
    m_numerator(num), m_denominator(den) {}

// generic constructor2
Fraction::Fraction(int num):
    m_numerator(num), m_denominator(1) {}

// overloading + (addition with fraction)
Fraction Fraction::operator+(const Fraction& frac){
    int num, den;
    
    den = (abs(m_denominator) * abs(frac.m_denominator)) / gcd(m_denominator, frac.m_denominator);
    num = (m_numerator * (den / m_denominator)) + (frac.m_numerator * (den / frac.m_denominator));
    
    den = den / gcd(num, den);
    num = num / gcd(num, den);
    
    return Fraction(num, den);
}

// overloading - (subtraction with fraction)
Fraction Fraction::operator-(const Fraction& frac){
    int num, den;
    
    den = (m_denominator * frac.m_denominator) / gcd(m_denominator, frac.m_denominator);
    num = (m_numerator * (den / m_denominator)) - (frac.m_numerator * (den / frac.m_denominator));
    
    den = den / gcd(num, den);
    num = num / gcd(num, den);
    
    return Fraction(num, den);
}

// overloading * (multiplication with fraction)
Fraction Fraction::operator*(const Fraction& frac){
    int num, den;

    num = m_numerator * frac.m_numerator;
    den = m_denominator * frac.m_denominator;

    num = num / gcd(num,den);
    den = den / gcd(num,den);

    return Fraction(num, den);
}

// overloading + (addition with integer)
Fraction Fraction::operator+(const int whole){
    return *this + Fraction(whole);
}

// overloading - (subtraction with integer)
Fraction Fraction::operator-(const int whole){
    return *this - Fraction(whole);
}

// overloading == (conditional is-equal)
bool Fraction::operator==(const Fraction& frac){
    return (m_numerator==frac.m_numerator) && (m_denominator==frac.m_denominator);
}

// overloading < (less than)
bool Fraction::operator<(const Fraction& frac){
    return ((m_numerator*frac.m_denominator) < (frac.m_numerator*m_denominator));
}

// overloading > (grater than)
bool Fraction::operator>(const Fraction& frac){
    return ((m_numerator*frac.m_denominator) > (frac.m_numerator*m_denominator));
}

// simplify fraction
Fraction Fraction::simplify(){
    int num, den;
    num = m_numerator / gcd(m_numerator,m_denominator);
    den = m_denominator / gcd(m_numerator, m_denominator);

    return Fraction(num, den);
}

// return true if fraction is irreducible
bool Fraction::isSimplest() const{
    return (gcd(m_numerator, m_denominator)==1);
}

// display fraction
void Fraction::display() const{
    std::cout << m_numerator << "/" << m_denominator << std::endl;
    return;
}

// overload << (ostream)
std::ostream& operator<<(std::ostream& rout, const Fraction& frac){
    rout << frac.m_numerator << "/" << frac.m_denominator;
    return rout;
}


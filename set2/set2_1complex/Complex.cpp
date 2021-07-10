#include <iostream>
#include "Complex.h"

// default constructor
Complex::Complex():
    m_real(0), m_imag(0) {}

// generic constructor1
Complex::Complex(int r, int i):
    m_real(r), m_imag(i) {}

// generic constructor2
Complex::Complex(int r):
    m_real(r), m_imag(0) {}

// overloading + (addition)
Complex Complex::operator+(const Complex& c1){
    int r = m_real + c1.m_real;
    int i = m_imag + c1.m_imag;
    return Complex(r,i);
}

// overloading - (subtraction)
Complex Complex::operator-(const Complex& c1){
    int r = m_real - c1.m_real;
    int i = m_imag - c1.m_imag;
    return Complex(r,i);
}

// overloading * (multiplication)
Complex Complex::operator*(const Complex& c1){
    int r = (m_real*c1.m_real) - (m_imag*c1.m_imag);
    int i = m_real*c1.m_imag + m_imag*c1.m_real;
    return Complex(r,i);
}

// overloading ++ (pre-increment)
Complex& Complex::operator++(){
    ++m_real;
    return *this;
}

// overloading ++ (post-increment)
Complex Complex::operator++(int dummy){
    Complex orig(m_real, m_imag);
    ++m_real;
    return orig;
}

// overloading == (conditional is-equal)
bool Complex::operator==(const Complex& c1){
    return ((m_real==c1.m_real) && (m_imag==c1.m_imag));
}

// show complex number
void Complex::display() const{
    std::cout << m_real;
    if(m_imag<0) std::cout << " - ";
    else std::cout << " + ";
    std::cout << abs(m_imag) << "i\n";
    return;
}

// overloading << (ostream)
std::ostream& operator<<(std::ostream& rout, const Complex& c1){
    char sign = (c1.m_imag<0) ? '-' : '+';
    rout << c1.m_real << " " << sign << " " << abs(c1.m_imag) << "i";
    return rout;
}

int Complex::get_imag() const {
    return m_imag;
}

int Complex::get_real() const {
    return m_real;
}
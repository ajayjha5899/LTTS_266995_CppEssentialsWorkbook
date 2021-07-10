#include <iostream>
#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
    int m_real;
    int m_imag;
public:
    Complex();
    Complex(int,int);
    Complex(int);
    Complex operator+(const Complex&);
    Complex operator-(const Complex&);
    Complex operator*(const Complex&);
    Complex& operator++();
    Complex operator++(int);
    bool operator==(const Complex&);
    void display() const;
    friend std::ostream& operator<<(std::ostream&, const Complex&);

    // for tests
    int get_real() const;
    int get_imag() const;
};

#endif
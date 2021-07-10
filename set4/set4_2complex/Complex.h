#include <iostream>

#ifndef COMPLEX_H
#define COMPLEX_H

template<typename T>
class Complex {
    T m_real;
    T m_imag;
public:
    Complex(): m_real(), m_imag() {}
    Complex(T real,T imag): m_real(real), m_imag(imag) {}
    void display(){
        std::cout << "real part = " << m_real << std::endl;
        std::cout << "imaginary part = " << m_imag << std::endl;
    }
};

#endif
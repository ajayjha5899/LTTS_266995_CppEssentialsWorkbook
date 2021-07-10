#include <iostream>
#include <string>
#include <cstring>
#include "Color.h"

// defualt constructor
Color::Color():
    m_r(0), m_g(0), m_b(0) {}

// generic constructor1
Color::Color(int r, int g, int b):
    m_r(r), m_g(g), m_b(b) {}

// generic constructor2
Color::Color(int hexa):
    m_r((hexa>>16) & 0xFF), m_g((hexa>>8) & 0xFF), m_b(hexa & 0xFF) {}

// generic constructor3
// string as "0xFF5832"
Color::Color(std::string hexa):
    m_r((std::stoi(hexa,0,16)>>16) & 0xFF), 
    m_g((std::stoi(hexa,0,16)>>8) & 0xFF), 
    m_b(std::stoi(hexa,0,16) & 0xFF) {}

// generic constructor4
Color::Color(color_t clr):
    m_r((clr>>16) & 0xFF), m_g((clr>>8) & 0xFF), m_b(clr & 0xFF) {}

// color inversion
void Color::invert(){
    m_r = 255 - m_r;
    m_g = 255 - m_g;
    m_b = 255 - m_b;
    return;
}

// show RGB values
void Color::display() const{
    std::cout << "Red - " << m_r << std::endl;
    std::cout << "Green - " << m_g << std::endl;
    std::cout << "Blue - " << m_b << std::endl;
    return;
}

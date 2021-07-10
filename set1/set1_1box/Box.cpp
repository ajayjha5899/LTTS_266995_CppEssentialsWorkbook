#include <iostream>
#include "Box.h"

// default constructor
Box::Box(): 
    m_length(1), m_breadth(1), m_height(1) {}

// constructor for cuboid
Box::Box(int l, int b, int h): 
    m_length(l), m_breadth(b), m_height(h) {}

// constructor for cube
Box::Box(int s):
    m_length(s), m_breadth(s), m_height(s) {}

// copy constructor
Box::Box(const Box &ref):
    m_length(ref.m_length), 
    m_breadth(ref.m_breadth), 
    m_height(ref.m_height) {}

// returns length of the box
int Box::length() const{
    return m_length;
}

// returns breadth of the box
int Box::breadth() const{
    return m_breadth;
}

// returns height of the box
int Box::height() const{
    return m_height;
}

// returns volume of the box
int Box::volume() const{
    return m_length * m_breadth * m_height;
}

void Box::display() const{
    std::cout << "Length = " << m_length << std::endl;
    std::cout << "Breadth = " << m_breadth << std::endl;
    std::cout << "Height = " << m_height << std::endl;
}
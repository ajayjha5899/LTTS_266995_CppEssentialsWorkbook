#include <iostream>
#include <cmath>
#include "Point.h"

// default constructor
Point::Point():
    m_x(0), m_y(0) {}

// generic constructor
Point::Point(int x, int y):
    m_x(x), m_y(y) {}

// copy constructor
Point::Point(const Point &p):
    m_x(p.m_x), m_y(p.m_y) {}

// returns distance of point from origin
double Point::distanceFromOrigin() const{
    double ans;
    ans = sqrt((m_x*m_x) + (m_y*m_y));
    return ans;
}

// returns cartesian quadrant of point
Quadrant Point::quadrant() const{
    Quadrant ans;
    if(m_x>=0 && m_y>=0) ans = Q1;
    if(m_x>=0 && m_y<0)  ans = Q4;
    if(m_x<0 && m_y>=0)  ans = Q2;
    if(m_x<0 && m_y<0)   ans = Q3;

    return ans;
}

// returns true if point is (0,0)
bool Point::isOrigin() const{
    return (m_x==0 && m_y==0);
}

// returns true if point is on x-axis
bool Point::isOnXAxis() const{
    return (m_y==0);
}

// returns true if point is on y-axis
bool Point::isOnYAxis() const{
    return (m_x==0);
}

void Point::display() const{
    std::cout << "X = " << m_x << std::endl;
    std::cout << "Y = " << m_y << std::endl;
    return;
}
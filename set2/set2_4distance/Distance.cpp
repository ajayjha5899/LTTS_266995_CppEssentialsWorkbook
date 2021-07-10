#include <iostream>
#include "Distance.h"

// default constructor
Distance::Distance():
    m_feets(0), m_inches(0) {}

// generic constructor1
Distance::Distance(int feets, int inches):
    m_feets(feets), m_inches(inches) {}

// generic constructor2
Distance::Distance(int inches):
    m_feets(inches/12), m_inches(inches%12) {}

// overloading + (addition)
Distance Distance::operator+(const Distance& dist){
    int feets, inches;

    inches = (m_inches + dist.m_inches) % 12;
    feets = (m_feets + dist.m_feets) + ((m_inches + dist.m_inches)/12);

    return Distance(feets, inches);
}

// overloading - (subtraction)
Distance Distance::operator-(const Distance& dist){
    int feets, inches;

    inches = m_inches - dist.m_inches;
    if(inches < 0){
        inches = 12 + inches;
        feets = m_feets - dist.m_feets - 1;
    }
    else feets = m_feets - dist.m_feets;

    return Distance(feets, inches);
}

//overloading + (additon with inches)
Distance Distance::operator+(int dist){
    return *this + Distance(dist);
}

//overloading - (subtracton with inches)
Distance Distance::operator-(int dist){
    return *this - Distance(dist);
}

// overloading ++ (pre-increment)
Distance& Distance::operator++(){
    *this = *this + Distance(1);
    return *this;
}

// overloading ++ (post-increment)
Distance Distance::operator++(int dummy){
    Distance orig(m_feets, m_inches);
    *this = *this + Distance(1);
    return orig;
}

// overloading == (conditional is-equal)
bool Distance::operator==(const Distance& dist){
    return ((m_feets==dist.m_feets) && (m_inches==dist.m_inches));
}

// overloading > (conditional is-greater)
bool Distance::operator>(const Distance& dist){
    if(m_feets > dist.m_feets) return true;
    if(m_feets == dist.m_feets){
        if(m_inches > dist.m_inches) return true;
    }
    return false;
}

// overloading < (conditional is-lesser)
bool Distance::operator<(const Distance& dist){
    if(m_feets < dist.m_feets) return true;
    if(m_feets == dist.m_feets){
        if(m_inches < dist.m_inches) return true;
    }
    return false;
}

// display distance
void Distance::display() const{
    std::cout << m_feets << "ft " << m_inches << "in\n";
    return;
}

// overloading << (ostream)
std::ostream& operator<<(std::ostream& rout, const Distance& dist){
    rout << dist.m_feets << "ft " << dist.m_inches << "in";
    return rout;
}


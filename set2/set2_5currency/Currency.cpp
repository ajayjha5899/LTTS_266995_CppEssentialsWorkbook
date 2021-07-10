#include <iostream>
#include "Currency.h"

// default constructor
Currency::Currency():
    m_rupees(0), m_paise(0) {}

// generic constructor1
Currency::Currency(int rupees, int paise):
    m_rupees(rupees), m_paise(paise) {}

// generic constructor2
Currency::Currency(int paise):
    m_rupees(paise/100), m_paise(paise%100) {}

// overloading + (addition)
Currency Currency::operator+(const Currency& curr){
    int rupees, paise;

    paise = (m_paise + curr.m_paise) % 100;
    rupees = m_rupees + curr.m_rupees + ((m_paise + curr.m_paise) / 100);

    return Currency(rupees, paise);
}

// overloading - (subtraction)
Currency Currency::operator-(const Currency& curr){
    int rupees, paise;

    paise = m_paise - curr.m_paise;

    if(paise < 0){
        paise = 100 + paise;
        rupees = m_rupees - curr.m_rupees - 1;
    }

    else rupees = m_rupees - curr.m_rupees;

    return Currency(rupees, paise);
}

// overloading + (addtion with paise)
Currency Currency::operator+(int paise){
    return *this + Currency(paise);
}

// overloading - (subtraction with paise)
Currency Currency::operator-(int paise){
    return *this - Currency(paise);
}

// overloading ++ (pre-increment)
Currency& Currency::operator++(){
    *this = *this + Currency(1);
    return *this;
}

// overloading ++ (post-increment)
Currency Currency::operator++(int dummy){
    Currency orig(m_rupees, m_paise);
    *this = *this + Currency(1);
    return orig;
}

// overloading == operator (conditional is-equal)
bool Currency::operator==(const Currency& curr){
    return ((m_rupees == curr.m_rupees) && (m_paise == curr.m_paise));
}

// overloading < operator (conditional lesser than)
bool Currency::operator<(const Currency& curr){
    if(m_rupees < curr.m_rupees) return true;

    if(m_rupees == curr.m_rupees){
        if(m_paise < curr.m_paise) return true;
    }

    return false;
}

// overloading > operator (conditional greater than)
bool Currency::operator>(const Currency& curr){
    if(m_rupees > curr.m_rupees) return true;

    if(m_rupees == curr.m_rupees){
        if(m_paise > curr.m_paise) return true;
    }

    return false;
}

// display currency
void Currency::dispaly() const {
    std::cout << "Rs. " << m_rupees << "." << m_paise << std::endl;
    return;
}

// overload << (ostream)
std::ostream& operator<<(std::ostream& rout, const Currency& curr){
    rout << "Rs. " << curr.m_rupees << "." << curr.m_paise;
    return rout;
}
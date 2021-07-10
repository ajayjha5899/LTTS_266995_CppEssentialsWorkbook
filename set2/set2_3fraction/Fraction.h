#include <iostream>
#ifndef FRACTION_H
#define FRACTION_H

class Fraction {
    int m_numerator;
    int m_denominator;
public:
    Fraction();
    Fraction(int,int);
    Fraction(int);
    Fraction operator+(const Fraction&);
    Fraction operator-(const Fraction&);
    Fraction operator*(const Fraction&);
    Fraction operator+(const int);
    Fraction operator-(const int);
    bool operator==(const Fraction&);
    bool operator<(const Fraction&);
    bool operator>(const Fraction&);
    Fraction simplify();
    bool isSimplest() const;
    void display() const;
    friend std::ostream& operator<<(std::ostream&, const Fraction&);
};

#endif
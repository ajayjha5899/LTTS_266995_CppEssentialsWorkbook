#include <iostream>
#include <string>
#ifndef IP_H
#define IP_H

enum IPClass {
    A,
    B,
    C,
    D
};

class IPAddress {
    uint32_t ipval;
public:
    IPAddress();
    IPAddress(uint8_t,uint8_t,uint8_t,uint8_t);   //a,b,c,d vals
    IPAddress(std::string);                       //"a.b.c.d" format
    bool isLoopBack() const;
    IPClass getIPClass() const;
    void display() const;
};

#endif
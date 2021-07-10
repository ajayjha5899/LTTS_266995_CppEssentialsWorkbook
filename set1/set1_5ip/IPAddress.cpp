#include <iostream>
#include <string>
#include "IPAddress.h"

// default constructor (127.0.0.1)
IPAddress::IPAddress(): ipval(0x7F000001) {}

// generic constructor1
IPAddress::IPAddress(uint8_t a, uint8_t b, uint8_t c, uint8_t d): 
    ipval((a<<24) | (b<<16) | (c<<8) | d) {}

// generic constructor2 
IPAddress::IPAddress(std::string ip){
    int start = 0, inat = 0;
    uint8_t vals[4];
    for(int i=1; i<ip.length(); i++){
        if(ip[i]=='.'){
            std::string octet = ip.substr(start, i-start);
            vals[inat] = std::stoi(octet);
            inat++; start = i+1;
        }
    }
    this->ipval = ((vals[0]<<24) | (vals[1]<<16) | (vals[2]<<8) | vals[3]);
}
    

// return true if ipval is 127.0.0.1
bool IPAddress::isLoopBack() const {
    return (ipval == 0x7F000001);
}

// return class of IP address 
IPClass IPAddress::getIPClass() const {
    uint8_t octet;
    octet = ((ipval & 0xFF000000)>>24);
    
    bool ca = (octet >= 1 && octet <= 127);
    bool cb = (octet >= 128 && octet <= 191);
    bool cc = (octet >= 192 && octet <= 223);

    if(ca && !cb && !cc) return A;
    else if(!ca && cb && !cc) return B;
    else if(!ca && !cb && cc) return C;
    else return D;
}

void IPAddress::display() const {
    std::string ip;
    uint8_t octets[4];
    octets[0] = ((ipval & 0xFF000000)>>24);
    octets[1] = ((ipval & 0xFF0000)>>16);
    octets[2] = ((ipval & 0xFF00)>>8);
    octets[3] = (ipval & 0xFF);

    for(int i=0; i<3; i++){
        ip.append(std::to_string(octets[i]));
        ip.append(".");
    }
    ip.append(std::to_string(octets[3]));
    std::cout << "IP Address is " << ip << std::endl;

}

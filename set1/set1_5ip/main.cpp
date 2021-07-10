#include <iostream>
#include <string>
#include "IPAddress.h"

int main(){
    IPAddress ip1;
    IPAddress ip2("49.36.22.193");
    IPAddress ip3(223,255,0,193);    //223.255.255.255

    if(ip1.isLoopBack()) std::cout << "ip1 is loop back.\n";
    else std::cout << "ip1 is not loop back.\n";

    switch(ip1.getIPClass()){
        case A:
            std::cout << "ip1 is class A.\n";
            break;
        case B:
            std::cout << "ip1 is class B.\n";
            break;
        case C:
            std::cout << "ip1 is class C.\n";
            break;
        case D:
            std::cout << "ip1 is class D.\n";
            break;
        default :
            std::cout << "Invalid class.\n";
    }

    switch(ip2.getIPClass()){
        case A:
            std::cout << "ip2 is class A.\n";
            break;
        case B:
            std::cout << "ip2 is class B.\n";
            break;
        case C:
            std::cout << "ip2 is class C.\n";
            break;
        case D:
            std::cout << "ip2 is class D.\n";
            break;
        default :
            std::cout << "Invalid class.\n";
    }

    switch(ip3.getIPClass()){
        case A:
            std::cout << "ip3 is class A.\n";
            break;
        case B:
            std::cout << "ip3 is class B.\n";
            break;
        case C:
            std::cout << "ip3 is class C.\n";
            break;
        case D:
            std::cout << "ip3 is class D.\n";
            break;
        default :
            std::cout << "Invalid class.\n";
    }

    ip1.display();
    ip2.display();
    ip3.display();

}
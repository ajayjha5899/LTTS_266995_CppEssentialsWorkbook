#include <iostream>
#include <string>
#include <cstring>
#include "Color.h"

int main(){
    Color c1;
    Color c2(255,255,255);
    Color c3(0xFF);
    Color c4("0x00FFFF");

    c4.display();
    std::cout << std::endl;
    
    c4.invert();
    c4.display();
    std::cout << std::endl;
    
    c3.display();
    std::cout << std::endl;
    
    c2.display();
    std::cout << std::endl;
    
    c1.display();
    std::cout << std::endl;
    
    

    return 0;
}
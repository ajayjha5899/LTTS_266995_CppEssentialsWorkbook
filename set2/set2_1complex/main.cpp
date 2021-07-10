#include <iostream>
#include "Complex.h"

int main(){
    Complex c1; c1.display();
    Complex c2(5,8); c2.display();
    Complex c3(-4,10); c3.display();
    Complex c4(11); c4.display();

    Complex c5 = c2 + c3; c5.display();
    
    Complex c6 = c3 - c2; c6.display();
    
    Complex c7 = c2 * c3; std::cout << c7 << std::endl;
    
    c1++; std::cout << c1 << std::endl;
    
    ++c4; std::cout << c4 << std::endl;

    if(c2==c4) std::cout << c2 << " and " << c4 << " are equal.\n";
    std::cout << c2 << " and " << c4 << " are not equal.\n";

    return 0;
}
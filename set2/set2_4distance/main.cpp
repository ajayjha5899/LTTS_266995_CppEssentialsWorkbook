#include <iostream>
#include "Distance.h"

int main(){
    Distance d1; d1.display();
    Distance d2(6,3); d2.display();
    Distance d3(5,11); d3.display();
    Distance d4(6); d4.display();

    std::cout << d2 + d3 << std::endl;

    std::cout << d2 - d3 << std::endl;

    std::cout << d2 + 58 << std::endl;

    std::cout << d2 - 58 << std::endl;

    std::cout << ++d1 << std::endl;
    
    std::cout << d1++ << std::endl;

    if(d1==d4) std::cout << d1 << " is equal to " << d4 << ".\n";
    else std::cout << d1 << " is not equal to " << d4 << ".\n";

    if(d1>d4) std::cout << d1 << " is greater than " << d4 << ".\n";
    else std::cout << d1 << " is not greater than " << d4 << ".\n";

    if(d1<d4) std::cout << d1 << " is smaller than " << d4 << ".\n";
    else std::cout << d1 << " is not smaller than " << d4 << ".\n";

    return 0;
}
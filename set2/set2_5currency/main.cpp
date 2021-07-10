#include <iostream>
#include "Currency.h"

int main(){
    Currency c1; c1.dispaly();
    Currency c2(58,99); c2.dispaly();
    Currency c3(20,11); c3.dispaly();
    Currency c4(99); c4.dispaly();

    std::cout << c2 + c3 << std::endl;

    std::cout << c2 - c3 << std::endl;

    std::cout << c2 + 101 << std::endl;

    std::cout << c2 - 899 << std::endl;

    std::cout << ++c4 << std::endl;

    std::cout << c4++ << std::endl;

    if(c3==c4) std::cout << c3 << " is equal to " << c4 << std::endl;
    else std::cout << c3 << " is not equal to " << c4 << std::endl;

    if(c3<c4) std::cout << c3 << " is lesser than " << c4 << std::endl;
    else std::cout << c3 << " is not lesser than " << c4 << std::endl;

    if(c3>c4) std::cout << c3 << " is greater than " << c4 << std::endl;
    else std::cout << c3 << " is not greater than " << c4 << std::endl;

    return 0;
}
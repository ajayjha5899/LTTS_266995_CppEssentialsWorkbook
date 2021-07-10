#include <iostream>
#include "Fraction.h"

int main(){
    Fraction f1; f1.display();
    Fraction f2(5,8); f2.display();
    Fraction f3(7,12); f3.display();
    Fraction f4(10); f4.display();

    std::cout << f2 + f3 << std::endl;

    std::cout << f2 - f3 << std::endl;

    std::cout << f2 * f3 << std::endl;

    std::cout << f2 + 10 << std::endl;
    
    std::cout << f2 - 10 << std::endl;

    if(f2==f3) std::cout << f2 << " is equal to " << f3 << ".\n";
    else std::cout << f2 << " is not equal to " << f3 << ".\n";

    if(f2>f3) std::cout << f2 << " is greater than " << f3 << ".\n";
    else std::cout << f2 << " is not greater than " << f3 << ".\n";

    if(f2<f3) std::cout << f2 << " is smaller than " << f3 << ".\n";
    else std::cout << f2 << " is not smaller than " << f3 << ".\n";

    Fraction f5(42,422);
    if(f5.isSimplest()) std::cout << f5 << " is in simplest form.\n";
    std::cout << f5 << " is not in simplest form.\n";
    
    f5 = f5.simplify(); 
    if(f5.isSimplest()) std::cout << f5 << " is in simplest form.\n";
    else std::cout << f5 << " is not in simplest form.\n";
    
    return 0;
}
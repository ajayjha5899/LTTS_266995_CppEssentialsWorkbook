#include <iostream>
#include "Box.h" 

int main(){
    Box b1;
    Box b2(9,8,5);
    Box b3(10);
    Box b4(b2);

    std::cout << "Length of b2 = " << b2.length() << std::endl;
    std::cout << "Breadth of b2 = " << b2.breadth() << std::endl;
    std::cout << "Height of b2 = " << b2.height() << std::endl;

    std::cout << "Volume of b3 = " << b3.volume() << std::endl;

    b4.display();

    return 0;
}
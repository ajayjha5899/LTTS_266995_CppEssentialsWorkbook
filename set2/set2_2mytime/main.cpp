#include <iostream>
#include "MyTime.h"

int main(){
    MyTime t1; t1.display();
    MyTime t2(5,8,58); t2.display();
    MyTime t3(10,57); t3.display();
    
    std::cout << t2 + t3 << std::endl;
    
    std::cout << t3 - t2 << std::endl;
    
    std::cout << t2 + 589 << std::endl;
    
    std::cout << t2 - 580 << std::endl;
    
    t2++; t2.display();
    
    ++t2; t2.display();
    
    t3 += t1; t3.display();
    
    if(t3==t1) std::cout << "t1 and t3 are equal.\n";
    else std::cout << "t1 and t3 are not equal.\n";

    if(t3>t1) std::cout << "t3 is ahead of t1.\n";
    else std::cout << "t3 is behind or equal to t1.\n";

    if(t2<t3) std::cout << "t3 is ahead of t2.\n";
    else std::cout << "t3 is behind or equal t2.\n";

    return 0;
}
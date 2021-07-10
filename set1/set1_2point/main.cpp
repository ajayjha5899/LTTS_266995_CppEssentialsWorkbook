#include <iostream>
#include <cmath>
#include "Point.h"

int main(){
    Point p1;
    Point p2(5,8);
    Point p3(20,-11);
    Point p4(p1);

    std::cout << "Distance of p2 from origin = " << p2.distanceFromOrigin() << std::endl;
    
    std::cout << "Distance of p3 from origin = " << p3.distanceFromOrigin() << std::endl;

    std::cout << "Qudrant of p2 = " << p2.quadrant() << std::endl;

    std::cout << "Qudrant of p3 = " << p3.quadrant() << std::endl;

    if(p1.isOrigin()) std::cout << "p1 is origin." << std::endl;
    else std::cout << "p1 is not origin." << std::endl;

    if(p2.isOrigin()) std::cout << "p2 is origin." << std::endl;
    else std::cout << "p2 is not origin." << std::endl;

    if(p4.isOrigin()) std::cout << "p4 is origin." << std::endl;
    else std::cout << "p4 is not origin." << std::endl;

    if(p1.isOnXAxis()) std::cout << "p1 is on X-axis." << std::endl;
    else std::cout << "p1 is not on X-axis" << std::endl;

    if(p3.isOnXAxis()) std::cout << "p3 is on X-axis." << std::endl;
    else std::cout << "p3 is not on X-axis" << std::endl;

    if(p1.isOnYAxis()) std::cout << "p1 is on Y-axis." << std::endl;
    else std::cout << "p1 is not on Y-axis" << std::endl;

    if(p2.isOnYAxis()) std::cout << "p2 is on Y-axis." << std::endl;
    else std::cout << "p2 is not on Y-axis" << std::endl;

    p4.display();

    return 0;

}
#include <iostream>
#include "Complex.h"

int main(){
    Complex<int> c1(5,8);
    Complex<double> c2(-5.9,8.42);

    c1.display();
    c2.display();
}

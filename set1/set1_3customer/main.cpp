#include <iostream>
#include <string>
#include <cstring>
#include "Customer.h"

int main(){
    Customer c1;
    Customer c2("5899", "Ajay", "9898989898", 100.0, Prepaid);
    Customer c3("201195", "Ankita", "8989898989", 500.0, Postpaid);
    Customer c4(c2);

    c2.display();
    c2.credit(400.0);
    std::cout << "Balance of c2 = Rs. " << c2.getBalance() << std::endl;
    c2.makeCall(300.0);
    std::cout << "Balance of c2 = Rs. " << c2.getBalance() << std::endl;
    c2.makeCall(300.0);
    std::cout << "Balance of c2 = Rs. " << c2.getBalance() << std::endl;

    std::cout << "\n\n";
    c1.display();
    
    std::cout << "\n\n";
    c4.display();

    std::cout << "\n\n";
    c3.display();
    c3.credit(400.0);
    std::cout << "Balance of c3 = Rs. " << c3.getBalance() << std::endl;
    c3.makeCall(300.0);
    std::cout << "Balance of c3 = Rs. " << c3.getBalance() << std::endl;
    c3.makeCall(300.0);
    std::cout << "Balance of c3 = Rs. " << c3.getBalance() << std::endl;

}
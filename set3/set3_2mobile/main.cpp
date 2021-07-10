#include <iostream>
#include <string>
#include "Mobile.h"

void trigger(CustomerBase* ptr){
    ptr->display();
    
    ptr->credit(1.01);
    std::cout << "Balance: " << ptr->getBalance() << std::endl;

    ptr->makeCall(60.0);
    std::cout << "Balance: " << ptr->getBalance() << std::endl;

    ptr->makeCall(60.0);
    std::cout << "Balance: " << ptr->getBalance() << std::endl;
    
    return;
}

int main(){
    CustomerBase *ptr;
    PrepaidCustomer pre1("A5899", "Ajay", "9898989898", 58.99);
    PostpaidCustomer post1("A17199", "Abhishek", "8989898989", 17.1,5082021);

    ptr = &pre1;
    trigger(ptr);

    ptr = &post1;
    trigger(ptr);

    return 0;
}
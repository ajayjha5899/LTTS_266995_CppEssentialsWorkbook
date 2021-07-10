#include <iostream>
#include <string>
#include "Banking.h"

void trigger(AccountBase* ptr){
    ptr->display();

    std::cout << ptr->getBalance() << std::endl;
    ptr->credit(100.50);
    std::cout << "Credit by 100.50\n";
    std::cout << ptr->getBalance() << std::endl;
    ptr->debit(100.50);
    std::cout << "Debit by 100.50\n";
    std::cout << ptr->getBalance() << std::endl;
}

int main(){
    AccountBase *ptr;

    SavingsAccount s1("1074010105055899", "Ajay", 100.50);
    CreditAccount c1("1074010105052011", "Abhishek", 100.50);
    
    ptr = &s1;
    trigger(ptr);

    ptr = &c1;
    trigger(ptr);

    return 0;
}
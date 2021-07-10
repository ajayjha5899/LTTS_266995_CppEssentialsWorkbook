#include <iostream>
#include <string>
#include <cstring>
#include "Customer.h"

// default constructor
Customer::Customer():
    m_custId("0000"), 
    m_custName("XYZ"),
    m_phone("9999999999"),
    m_balance(0.0),
    m_type(Prepaid) {}

// generic constructor1
Customer::Customer(std::string id, std::string name, std::string phone, double balance, AccountType type):
    m_custId(id), 
    m_custName(name),
    m_phone(phone),
    m_balance(balance),
    m_type(type) {}

// generic constructor2
Customer::Customer(std::string id, std::string name, std::string phone):
    m_custId(id), 
    m_custName(name),
    m_phone(phone),
    m_balance(100.0),
    m_type(Prepaid) {}

// copy constructor
Customer::Customer(const Customer &c):
    m_custId(c.m_custId), 
    m_custName(c.m_custName),
    m_phone(c.m_phone),
    m_balance(c.m_balance),
    m_type(c.m_type) {}

// recharge or bill payment
void Customer::credit(double amount){
    switch(m_type){
        case Prepaid:
            m_balance += amount;
            break;

        case Postpaid:
            m_balance -= amount;
            break;

        default:
            std::cout << "[ERROR] Invalid account type." << std::endl;
    }
}

// makeCall
void Customer::makeCall(double amount){
    switch(m_type){
        case Prepaid:
            if(m_balance - amount >= 0) m_balance -= amount;
            else std::cout << "Cannot make call due to insufficient balance." << std::endl;
            break;

        case Postpaid:
            m_balance += amount;
            break;

        default:
            std::cout << "[ERROR] Invalid account type." << std::endl;
    }
}

// return balance
double Customer::getBalance() const{
    return m_balance;
}

void Customer::display() const{
    std::cout << "Customer details :\n";
    std::cout << ">> ID - " << m_custId << std::endl;
    std::cout << ">> Name - " << m_custName << std::endl;
    std::cout << ">> Phone - " << m_phone << std::endl;
    std::cout << ">> Balance - Rs. " << m_balance << std::endl;
    std::string type = (m_type==0) ? "Prepaid" : "Postpaid";
    std::cout << ">> Account type - " << type << std::endl;
}
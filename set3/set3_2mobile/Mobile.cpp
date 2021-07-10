#include <iostream>
#include <string>
#include "Mobile.h"

//=======<CustomerBase>=======

// defualt constructor
CustomerBase::CustomerBase():
    m_custId("XXXXX"),
    m_custName("NONAME"),
    m_phone("0000000000"),
    m_balance(0.0),
    m_type(Prepaid) {}

// generic constructor1
CustomerBase::CustomerBase(std::string custId,std::string custName,std::string phone,double balance,AccountType type):
    m_custId(custId),
    m_custName(custName),
    m_phone(phone),
    m_balance(balance),
    m_type(type) {}

// generic constructor2
CustomerBase::CustomerBase(std::string custId,std::string custName,std::string phone):
    m_custId(custId),
    m_custName(custName),
    m_phone(phone),
    m_balance(0.0),
    m_type(Prepaid) {}

// copy constructor
CustomerBase::CustomerBase(const CustomerBase& cus):
    m_custId(cus.m_custId),
    m_custName(cus.m_custName),
    m_phone(cus.m_phone),
    m_balance(cus.m_balance),
    m_type(cus.m_type) {}

// return balance
double CustomerBase::getBalance() const {
    return m_balance;
}

//=======</CustomerBase>=======


//=======<PrepaidCustomer>=======

// default constructor
PrepaidCustomer::PrepaidCustomer():
    CustomerBase() {}

// generic constructor1
PrepaidCustomer::PrepaidCustomer(std::string custId,std::string custName,std::string phone,double balance):
    CustomerBase(custId, custName, phone, balance, Prepaid) {}

// generic constructor2
PrepaidCustomer::PrepaidCustomer(std::string custId,std::string custName,std::string phone):
    CustomerBase(custId, custName, phone, 0.0, Prepaid) {}

// overriding credit
void PrepaidCustomer::credit(double amount){
    recharge(amount);
    return;
}

void PrepaidCustomer::recharge(double amount){
    m_balance += amount;
    return;
}

// overriding makeCall  
void PrepaidCustomer::makeCall(double amount) {
    if(amount > m_balance) std::cout << "Balance not sufficient.\n";
    else m_balance -= amount;

    return;
}

//overriding display
void PrepaidCustomer::display() const {
    std::cout << "Prepaid customer info" << std::endl;
    std::cout << ">> Customer id - " << m_custId << std::endl;
    std::cout << ">> Customer name - " << m_custName << std::endl;
    std::cout << ">> Phone number - " << m_phone << std::endl;
    std::cout << ">> Balance - " << m_balance << std::endl;
}

//=======</PrepaidCustomer>=======


//=======<PostpaidCustomer>=======

// default constructor
PostpaidCustomer::PostpaidCustomer():
    CustomerBase() {}

// generic constructor1
PostpaidCustomer::PostpaidCustomer(std::string custId,std::string custName,std::string phone,double balance, int billDate):
    CustomerBase(custId, custName, phone, balance, Postpaid),
    m_billDate(billDate) {}

// generic constructor2
PostpaidCustomer::PostpaidCustomer(std::string custId,std::string custName,std::string phone):
    CustomerBase(custId, custName, phone, 0.0, Postpaid) {}

// overriding credit
void PostpaidCustomer::credit(double amount){
    billPay(amount);
    return;
}

void PostpaidCustomer::billPay(double amount){
    m_balance -= amount;
    return;
}

// overriding makeCall  
void PostpaidCustomer::makeCall(double amount) {
    m_balance += amount;

    return;
}

//overriding display
void PostpaidCustomer::display() const {
    std::cout << "Postpaid customer info" << std::endl;
    std::cout << ">> Customer id - " << m_custId << std::endl;
    std::cout << ">> Customer name - " << m_custName << std::endl;
    std::cout << ">> Phone number - " << m_phone << std::endl;
    std::cout << ">> Balance - " << m_balance << std::endl;
    std::cout << ">> Bill date - " << m_billDate << std::endl;
}

//=======</PostpaidCustomer>=======
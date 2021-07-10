#include <string>
#ifndef CUSTOMER_H
#define CUTOMER_H

enum AccountType {
    Prepaid,
    Postpaid
};

class Customer {
    std::string m_custId;
    std::string m_custName;
    std::string m_phone; 
    double m_balance;
    AccountType m_type;
public:
    Customer();
    Customer(std::string,std::string,std::string,double,AccountType);
    Customer(std::string,std::string,std::string);
    Customer(const Customer&);
    void credit(double);           //recharge or billPay
    void makeCall(double);
    double getBalance() const;
    void display() const;
};

#endif
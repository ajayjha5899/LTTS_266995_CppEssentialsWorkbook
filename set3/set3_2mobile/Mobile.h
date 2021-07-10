#include <iostream>
#include <string>

#ifndef MOBILE_H
#define MOBILE_H

enum AccountType {
  Prepaid,
  Postpaid
};

class CustomerBase {
protected:
    std::string m_custId;
    std::string m_custName;
    std::string m_phone; 
    double m_balance;
    AccountType m_type;
 public:
    CustomerBase();
    CustomerBase(std::string,std::string,std::string,double,AccountType);
    CustomerBase(std::string,std::string,std::string);
    CustomerBase(const CustomerBase&);
    virtual void credit(double)=0;           //recharge or billPay
    virtual void makeCall(double)=0;
    double getBalance() const;
    virtual void display() const=0;
};

class PrepaidCustomer : public CustomerBase {
private:
    void recharge(double);
public:
    PrepaidCustomer();
    PrepaidCustomer(std::string,std::string,std::string,double);
    PrepaidCustomer(std::string,std::string,std::string);
    void credit(double);           //recharge or billPay
    void makeCall(double);
    void display() const;
};

class PostpaidCustomer : public CustomerBase {
private:
    void billPay(double);
    int m_billDate;
public:
    PostpaidCustomer();
    PostpaidCustomer(std::string,std::string,std::string,double,int);
    PostpaidCustomer(std::string,std::string,std::string);
    void credit(double);           //recharge or billPay
    void makeCall(double);
    void display() const;
};

#endif
#include <iostream>
#include <string>

#ifndef BANKING_H
#define BANKING_H

class AccountBase {
protected:
    std::string m_accNumber;
    std::string m_accName;
    double m_balance;
public:
    AccountBase();
    AccountBase(std::string,std::string,double);
    AccountBase(std::string,std::string);
    AccountBase(const AccountBase&);
    virtual void debit(double)=0;
    virtual void credit(double)=0;
    virtual void display() const = 0;
    double getBalance() const;
};

class SavingsAccount : public AccountBase {
public:
    SavingsAccount();
    SavingsAccount(std::string,std::string,double);
    SavingsAccount(std::string,std::string);
    void debit(double);
    void credit(double);
    void display() const;
};
class CreditAccount : public AccountBase {
public:
    CreditAccount();
    CreditAccount(std::string,std::string,double);
    CreditAccount(std::string,std::string);
    void debit(double);
    void credit(double);
    void display() const;
};

#endif
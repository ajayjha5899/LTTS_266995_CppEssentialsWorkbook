#include <iostream>
#include <string>
#include "Banking.h"

//=======<AccountBase>=======

// default constructor
AccountBase::AccountBase():
    m_accNumber("0000000000"),
    m_accName("NONAME"),
    m_balance(0.0) {}

// generic constructor1
AccountBase::AccountBase(std::string accNumber, std::string accName, double balance):
    m_accNumber(accNumber),
    m_accName(accName),
    m_balance(balance) {}

// generic constructor2
AccountBase::AccountBase(std::string accNumber, std::string accName):
    m_accNumber(accNumber),
    m_accName(accName),
    m_balance(0.0) {}

// copy constructor
AccountBase::AccountBase(const AccountBase& acc):
    m_accNumber(acc.m_accNumber),
    m_accName(acc.m_accName),
    m_balance(acc.m_balance) {}

// return balance
double AccountBase::getBalance() const {
    return m_balance;
}

//=======</AccountBase>=======


//=======<SavingsAccount>=======

// default constructor
SavingsAccount::SavingsAccount():
    AccountBase() {}

// generic constructor1
SavingsAccount::SavingsAccount(std::string accNumber, std::string accName, double balance):
    AccountBase(accNumber, accName, balance) {}

// generic constructor2
SavingsAccount::SavingsAccount(std::string accNumber, std::string accName):
    AccountBase(accNumber, accName) {}

// override debit
void SavingsAccount::debit(double amount){
    if(amount > m_balance) std::cout << "Not enough balance.\n";
    else m_balance -= amount;

    return;
}

// override credit
void SavingsAccount::credit(double amount){
    m_balance += amount;

    return;
}

// override display
void SavingsAccount::display() const {
    std::cout << "Savings Account Details:" << std::endl;
    std::cout << ">> Account number - " << m_accNumber << std::endl;
    std::cout << ">> Account name - " << m_accName << std::endl;
    std::cout << ">> Balance - " << m_balance << std::endl;
}

//=======</SavingsAccount>=======


//=======<CreditAccount>=======

// default constructor
CreditAccount::CreditAccount():
    AccountBase() {}

// generic constructor1
CreditAccount::CreditAccount(std::string accNumber, std::string accName, double balance):
    AccountBase(accNumber, accName, balance) {}

// generic constructor2
CreditAccount::CreditAccount(std::string accNumber, std::string accName):
    AccountBase(accNumber, accName) {}

// override debit
void CreditAccount::debit(double amount){
    m_balance += amount;

    return;
}

// override credit
void CreditAccount::credit(double amount){
    m_balance -= amount;

    return;
}

// override display
void CreditAccount::display() const {
    std::cout << "Credit Account Details:" << std::endl;
    std::cout << ">> Account number - " << m_accNumber << std::endl;
    std::cout << ">> Account name - " << m_accName << std::endl;
    std::cout << ">> Balance - " << m_balance << std::endl;
}

//=======</CreditAccount>=======
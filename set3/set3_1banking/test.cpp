#include <iostream>
#include <gtest/gtest.h>
#include "Banking.h"

TEST(Banking, Savings_DefaultConstructor){
    AccountBase *ptr;
    SavingsAccount s1;
    ptr = &s1;
    ASSERT_EQ(0.0, ptr->getBalance());
}

TEST(Banking, Credit_DefaultConstructor){
    AccountBase *ptr;
    CreditAccount c1;
    ptr = &c1;
    ASSERT_EQ(0.0, ptr->getBalance());
}

TEST(Banking, Savings_ParameterizedConstructor1){
    AccountBase *ptr;
    SavingsAccount s1("1074010105055899", "Ajay");
    ptr = &s1;
    ASSERT_EQ(0.0, ptr->getBalance());
}

TEST(Banking, Credit_ParameterizedConstructor1){
    AccountBase *ptr;
    CreditAccount s1("1074010105055899", "Ajay");
    ptr = &s1;
    ASSERT_EQ(0.0, ptr->getBalance());
}

TEST(Banking, Savings_ParameterizedConstructor2){
    AccountBase *ptr;
    SavingsAccount s1("1074010105055899", "Ajay", 100.50);
    ptr = &s1;
    ASSERT_EQ(100.50, ptr->getBalance());
}

TEST(Banking, Credit_ParameterizedConstructor2){
    AccountBase *ptr;
    CreditAccount s1("1074010105055899", "Ajay", 100.50);
    ptr = &s1;
    ASSERT_EQ(100.50, ptr->getBalance());
}

TEST(Banking, Savings_CreditDebit){
    AccountBase *ptr;
    SavingsAccount s1("1074010105055899", "Ajay", 100.50);  
    ptr = &s1;
    ptr->credit(100.50);
    ASSERT_EQ(201, ptr->getBalance());
    ptr->debit(100.50);
    ASSERT_EQ(100.5, ptr->getBalance());
}

TEST(Banking, Credit_CreditDebit){
    AccountBase *ptr;
    CreditAccount s1("1074010105055899", "Ajay", 100.50);  
    ptr = &s1;
    ptr->credit(100.50);
    ASSERT_EQ(0, ptr->getBalance());
    ptr->debit(100.50);
    ASSERT_EQ(100.5, ptr->getBalance());
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
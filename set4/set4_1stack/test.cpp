#include <iostream>
#include <gtest/gtest.h>
#include "Stack.h"

TEST(MyStack, DefaultConstructor){
    MyStack<int> s1;
    bool cond1 = s1.isEmpty();
    bool cond2 = s1.isFull();
    ASSERT_EQ(true, cond1);
    ASSERT_EQ(false, cond2);
}

TEST(MyStack, ParameterizedConstructor){
    MyStack<int> s1(5);
    bool cond1 = s1.isEmpty();
    bool cond2 = s1.isFull();
    ASSERT_EQ(true, cond1);
    ASSERT_EQ(false, cond2);
}

TEST(MyStack, Push){
    MyStack<int> s1(5);
    for(int i=0; i<5; i++) s1.push(i);
    bool cond1 = s1.isEmpty();
    bool cond2 = s1.isFull();
    ASSERT_EQ(false, cond1);
    ASSERT_EQ(true, cond2);
    ASSERT_EQ(4, s1.peek());
}

TEST(MyStack, Pop){
    MyStack<int> s1(5);
    for(int i=0; i<5; i++) s1.push(i);
    int e = s1.pop();
    bool cond1 = s1.isEmpty();
    bool cond2 = s1.isFull();
    ASSERT_EQ(false, cond1);
    ASSERT_EQ(false, cond2);
    ASSERT_EQ(3, s1.peek());
    ASSERT_EQ(4, e);
}


int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
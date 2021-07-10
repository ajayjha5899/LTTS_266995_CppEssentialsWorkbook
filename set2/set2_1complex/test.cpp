#include <iostream>
#include <gtest/gtest.h>
#include "Complex.h"

TEST(Complex, DefaultConstructor){
    Complex c1;
    ASSERT_EQ(0, c1.get_imag());
    ASSERT_EQ(0, c1.get_real());
}

TEST(Complex, ParameterizedConstructor1){
    Complex c1(5);
    ASSERT_EQ(0, c1.get_imag());
    ASSERT_EQ(5, c1.get_real());
}

TEST(Complex, ParameterizedConstructor2){
    Complex c1(5,8);
    ASSERT_EQ(8, c1.get_imag());
    ASSERT_EQ(5, c1.get_real());
}

TEST(Complex, OverloadingAddition){
    Complex c1 = Complex(5,8) + Complex(5,8);
    ASSERT_EQ(16, c1.get_imag());
    ASSERT_EQ(10, c1.get_real());
}

TEST(Complex, OverloadingSubtraction){
    Complex c1 = Complex(5,8) - Complex(5,8);
    ASSERT_EQ(0, c1.get_imag());
    ASSERT_EQ(0, c1.get_real());
}

TEST(Complex, OverloadingMultiplication){
    Complex c1 = Complex(5,8) * Complex(0,0);
    ASSERT_EQ(0, c1.get_imag());
    ASSERT_EQ(0, c1.get_real());
}

TEST(Complex, OverloadingPreIncrement){
    Complex c1 = Complex(5,8);
    ++c1;
    ASSERT_EQ(8, c1.get_imag());
    ASSERT_EQ(6, c1.get_real());
}

TEST(Complex, OverloadingPostIncrement){
    Complex c1 = Complex(5,8);
    c1++;
    ASSERT_EQ(8, c1.get_imag());
    ASSERT_EQ(6, c1.get_real());
}

TEST(Complex, OverloadingConditionalIsEqual){
    bool cond1 = Complex() == Complex(5,8);
    bool cond2 = Complex(5,8) == Complex(5,8);
    ASSERT_EQ(false, cond1);
    ASSERT_EQ(true, cond2);
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
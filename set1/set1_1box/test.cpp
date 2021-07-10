#include <iostream>
#include <gtest/gtest.h>
#include "Box.h"

TEST(Box, DefaultConstructor){
    Box b1;
    ASSERT_EQ(1, b1.length());
    ASSERT_EQ(1, b1.breadth());
    ASSERT_EQ(1, b1.height());
    ASSERT_EQ(1, b1.volume());
}

TEST(Box, PrameterizedConstructor1){
    Box b1(5,8,9);
    ASSERT_EQ(5, b1.length());
    ASSERT_EQ(8, b1.breadth());
    ASSERT_EQ(9, b1.height());
    ASSERT_EQ(360, b1.volume());
}

TEST(Box, PrameterizedConstructor2){
    Box b1(5);
    ASSERT_EQ(5, b1.length());
    ASSERT_EQ(5, b1.breadth());
    ASSERT_EQ(5, b1.height());
    ASSERT_EQ(125, b1.volume());
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
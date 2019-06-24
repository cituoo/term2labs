//
// Created by Yaroslav Haus on 2019-06-20.
//
#include <iostream>

#include<gtest/gtest.h>
#include<gmock/gmock.h>

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}

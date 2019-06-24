// Copyright 2019 Yaroslav Haus

#include <gtest/gtest.h>
#include <exception>
#include <iostream>
#include "forward_list.hpp"


TEST(ForwardList, Init)
{
    ForwardList<int> clearList;
    EXPECT_EQ(clearList.empty(), true);


    std::string somestr = "abcd";
    ForwardList<char> charList;
    for (char letter : somestr)
        charList.push_back(letter);
    EXPECT_EQ(charList.size(), 4);
    EXPECT_EQ(charList[1], 'a');
    EXPECT_EQ(charList[2], 'b');
    EXPECT_EQ(charList[3], 'c');
    EXPECT_EQ(charList[4], 'd');


    ForwardList<char> eqCheck(charList);
    EXPECT_EQ(eqCheck.size(), charList.size());


    ForwardList<char> eqCheck2 = eqCheck;
    EXPECT_EQ(eqCheck2.size(), eqCheck.size());
}



TEST(ForwardList, Push)
{
    ForwardList<int> list1(5);
    list1.push_front(4);
    list1.push_back(6);

    EXPECT_EQ(list1[1], 4);
    EXPECT_EQ(list1[2], 5);
    EXPECT_EQ(list1[3], 6);
}

TEST(ForwardList, Pop)
{
    ForwardList<int> list1(5);
    list1.push_front(4);
    list1.push_back(6);
    list1.pop_back();
    EXPECT_EQ(list1.size(), 2);
    EXPECT_EQ(list1[2], 5);


    list1.pop_front();
    EXPECT_EQ(list1.size(), 1);
    EXPECT_EQ(list1[1], 5);


    ForwardList<char> list2Long('a');
    std::string anotherLatters = "bcde";
    for (char letter : anotherLatters)
        list2Long.push_back(letter);
    for (int i = 0; i < 3; i++)
        list2Long.pop_front();
    EXPECT_EQ(list2Long.size(), 2);
    EXPECT_EQ(list2Long[1], 'd');
}


TEST(ForwardList, Insert)
{
    std::vector<int> numbers = {2, 2, 2, 2, 2};
    ForwardList<int> listofnums;
    for (int number : numbers)
        listofnums.push_back(number);
    listofnums.insert_after(8, 4);
    EXPECT_EQ(listofnums[5], 8);
    EXPECT_EQ(listofnums.size(), 6);


    listofnums.erase(5);
    EXPECT_EQ(listofnums[5], 2);
    EXPECT_EQ(listofnums.size(), 5);
}

TEST(ForwardList, Swap)
{
    ForwardList<int> list1(1);
    list1.push_back(2);
    list1.push_back(3);
    list1.reverse();


    EXPECT_EQ(list1[1], 3);
    EXPECT_EQ(list1[2], 2);
    EXPECT_EQ(list1[3], 1);
}

TEST(ForwardList, Unique)
{
    ForwardList<char> listofletters('x');
    std::string testletters = "qqwerootgghrrj";
    for (char letter : testletters)
        listofletters.push_back(letter);
    bool is_unique = listofletters.unique('t');
    EXPECT_EQ(is_unique, true);
}

TEST(ForwardList, ListSwap)
{
    ForwardList<int> list1(1);
    list1.push_back(2);
    list1.push_back(3);
    ForwardList<int> list2 = list1.reverse();
    list1.reverse();
    ForwardList<int> list3 = list1.swap(list2);

    EXPECT_EQ(list1[1], 3);
    EXPECT_EQ(list1[2], 2);
    EXPECT_EQ(list1[3], 1);

    EXPECT_EQ(list2[1], 1);
    EXPECT_EQ(list2[2], 2);
    EXPECT_EQ(list2[3], 3);

    EXPECT_EQ(list3[1], 3);
    EXPECT_EQ(list3[2], 2);
    EXPECT_EQ(list3[3], 1);
}

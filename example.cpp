// Copyright 2019 Dan Kokin d_kokin@inbox.ru

#include <gtest/gtest.h>

#include <sstream>
#include <string.h>
#include "string.h"

TEST(String, ConstructAssign) {
const char* data = "some string";

String s0(data);
s0[0] = 'S';
String s1(s0);
s1[5] = 'S';

String s2;
s2 = s1;
s2[0] = 's';

EXPECT_EQ("Some string", s0);
EXPECT_EQ("Some String", s1);
EXPECT_EQ("some String", s2);
EXPECT_EQ(String("some string"), String(data));
}

TEST(String, GetByIndex) {
const char* data = "some string";

const String s1(data);

EXPECT_EQ('s', s1[0]);
EXPECT_EQ('m', s1[2]);
EXPECT_EQ('s', s1[5]);

String s(data);
s[2] = 'M';
s[5] = s[0] = 'S';

EXPECT_EQ('S', s[0]);
EXPECT_EQ('M', s[2]);
EXPECT_EQ('S', s[5]);
}

TEST(String, Append) {
String s1("some");
s1 += ' ';
s1 += String("string");

String s2 = String("some ") + String("string");

EXPECT_EQ(s1, s2);
}

TEST(String, Replace) {
String s1("some string");

s1.Replace('s', 'S');

EXPECT_EQ(String("Some String"), s1);
}

TEST(String, Size) {
String s1("some");

EXPECT_EQ(s1.Size(), 4);
EXPECT_TRUE(String{}.Empty());

EXPECT_FALSE(s1.Empty());
}

TEST(String, Mult) {
String s1("ABC");
s1 *= 3;

EXPECT_EQ(s1, String("ABCABCABC"));

String s2 = s1 * 3;
EXPECT_EQ(s2, String("ABCABCABCABCABCABCABCABCABC"));
}

TEST(String, Trim) {
String s("  abc   ____");

s.RTrim('_');
EXPECT_EQ(s, String("  abc   "));

s.LTrim(' ');
EXPECT_EQ(s, String("abc   "));

s.RTrim(' ');
EXPECT_EQ(s, String("abc"));
}

TEST(String, Find) {
String s1("some string");
String s2(" ");
EXPECT_EQ(4, s1.Find(s2));
String s3("str");
EXPECT_EQ(5, s1.Find(s3));
String s4("some");
EXPECT_EQ(0, s1.Find(s4));
String s5("not found");
EXPECT_EQ(static_cast<size_t>(-1), s1.Find(s5));
}

TEST(String, Stream) {
std::stringstream stream;
String s1("some string");
stream << s1 << " and " << String("stream");

EXPECT_EQ("some string and stream", stream.str());
}

TEST(String, Swap) {
String s0("some string");
String s1("other string");

EXPECT_EQ("some string", s0);
EXPECT_EQ("other string", s1);

s0.swap(s1);

EXPECT_EQ("other string", s0);
EXPECT_EQ("some string", s1);
}





/*
#include <iostream>
#include "string.h"

using namespace std;

int main()
{

    String string1 = "string1";     // оператор присваивания
    String string2 = string1;       // оператор копирования
    String string3("string3");      // конструктор с парметром
    string1.Show();
    string2.Show();
    string3.Show();
    string3 += string2;
    cout << "Значение string3: ";
    string3.Show();
    cout << " Проверка на пустоту До удаления: " << string3.Empty() << endl;
    string3 = "";
    cout << "Значение string3: ";
    string3.Show();
    cout << "Проверка на пустоту После удаления: " << string3.Empty() << endl;
    cout << "Равны ли стринг1 и стринг2: " << (string1 == string2) << endl;
    cout << "Стринг3 больше ли чем стринг 2: " << (string3<string2) << endl;
    string3 = "string3";
    string3.Replace('s', 'S');
    cout << "Заменим все s на S в стринг3: " << endl;
    string3.Show();
    String string4 = "Very big stroka";
    size_t indexfinded = string4.Find("Very");
    string4.Show();
    cout << "Индекс найденой подстроки: " << static_cast<int>(indexfinded) << endl;
    cout << "Размер стринга4: " << string4.Size() << endl;
    cout << "Пятый символ стринга 4: " << string4[5] << endl;
    String string5 = "___somebody__";
    string5.RTrim('_');
    string5.Show();
    string5.LTrim('_');
    string5.Show();




    return 0;
}
 */
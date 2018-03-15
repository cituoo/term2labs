#include <iostream>

#include "string.h"

int main()
{

    char * word1 = new char[3];
    for (int i = 0; i < 3; i++) { word1[i] = 'p'; }
    char * word2 = new char[3];
    for (int i = 0; i < 3; i++) { word2[i] = 'q'; }
    String test1;
    test1 = word1;
    test1.Show();
    String test2(word2);
    test2.Show();
    test1 = test2;
    test1.Show();
    test1 = "ppp";
    test1.Show();
    std::cout<<"-------"<<std::endl;
    test1 += test2;
    test1.Show();
    std::cout<<"-------"<<std::endl;
    String test3 = test2;
    test2 += test3;
    bool bol1 = (test1 == test2);
    bool bol2 = (test2 == test3);
    std::cout<<bol1<<"  "<<bol2<<std::endl;
    std::cout<<"-------"<<std::endl;
    test2 = "ppp";
    test3 = "qqq";
    bool bol3 = (test3 < test2);
    bool bol4 = (test2 < test1);
    std::cout<<bol3<<"  "<<bol4<<std::endl;
    std::cout<<"-------"<<std::endl;
    test1.Show();
    test2.Show();
    test3.Show();
    size_t q = test1.Find(test3);
    std::cout<<q;





    return 0;
}
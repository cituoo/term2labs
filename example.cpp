#include <iostream>

#include "string.h"

int main()
{

    char word1[] = "ppp";
    char word2[] = "qqq";
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
    String test4(word2);
    std::cout<<"\n-------"<<std::endl;
    test4.Show();
    test4.Replace('q', 'p');
    test4.Show();
    std::cout<<"-------"<<std::endl;
    test1.Show();
    std::cout<<test1.Size();
    std::cout<<"\n-------"<<std::endl;
    String brackets;
    brackets = "some string";
    std::cout<<brackets[0]<<std::endl;
    brackets[0] = 'S';
    brackets.Show();
    std::cout<<"-------"<<std::endl;





    return 0;
}
#include <iostream>

#include "MyString.h"

int main()
{
    MyString str1("very very very long string");
    str1.Reserve(30);

    std::cout << "Capacity : " << str1.Capacity() << std::endl;
    std::cout << "String length : " << str1.Length() << std::endl;
    str1.Println();
}
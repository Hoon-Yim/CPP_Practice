#include <iostream>

#include "MyString.h"

int main()
{
    MyString str1("very long string");
    MyString str2("<some string inserted between>");
    str1.Reserve(30);

    std::cout << "Capacity : " << str1.Capacity() << std::endl;
    std::cout << "String length : " << str1.Length() << std::endl;
    str1.Println();

    str1.Insert(5, str2);
    str1.Println();
}
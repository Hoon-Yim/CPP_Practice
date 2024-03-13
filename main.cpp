#include <iostream>

#include "MyString.h"

int main()
{
    MyString str1("Hello World");
    MyString str2(str1);

    str1.Println();
    str2.Println();
}

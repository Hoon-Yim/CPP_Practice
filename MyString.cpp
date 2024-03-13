#include <iostream>
#include <cstring>
#include "MyString.h"

MyString::MyString(char c)
{
    mStringContent = new char[1];
    mStringContent[0] = c;
    mStringLength = 1;
}

MyString::MyString(const char *str)
{
    mStringLength = strlen(str);
    mStringContent = new char[mStringLength];

    for (int i = 0; i != mStringLength; ++i)
    {
        mStringContent[i] = str[i];
    }
}

MyString::MyString(const MyString &str)
{
    mStringLength = str.mStringLength;
    mStringContent = new char[mStringLength];

    for (int i = 0; i < mStringLength; ++i)
    {
        mStringContent[i] = str.mStringContent[i];
    }
}

MyString::~MyString()
{
    delete[] mStringContent;
}

int MyString::Length() const
{
    return mStringLength;
}

void MyString::Print() const
{
    for (int i = 0; i < mStringLength; ++i)
    {
        std::cout << mStringContent[i];
    }
}

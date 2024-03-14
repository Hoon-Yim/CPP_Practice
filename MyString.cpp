#include <iostream>
#include <cstring>
#include "MyString.h"

MyString::MyString(char c)
{
    mStringContent = new char[1];
    mStringContent[0] = c;
    mStringLength = 1;
    mMemoryCapacity = 1;
}

MyString::MyString(const char *str)
{
    mStringLength = strlen(str);
    mMemoryCapacity = mStringLength;
    mStringContent = new char[mStringLength];

    for (int i = 0; i != mStringLength; ++i)
    {
        mStringContent[i] = str[i];
    }
}

MyString::MyString(const MyString &str)
{
    mStringLength = str.mStringLength;
    mMemoryCapacity = mStringLength;
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

int MyString::Capacity() const
{
    return mMemoryCapacity;
}

void MyString::Print() const
{
    for (int i = 0; i < mStringLength; ++i)
    {
        std::cout << mStringContent[i];
    }
}

void MyString::Println() const
{
    for (int i = 0; i < mStringLength; ++i)
    {
        std::cout << mStringContent[i];
    }
    std::cout << std::endl;
}

MyString &MyString::Assign(const MyString &str)
{
    if (str.mStringLength > mMemoryCapacity)
    {
        delete[] mStringContent;

        mStringContent = new char[str.mStringLength];
        mMemoryCapacity = str.mStringLength;
    }

    for (int i = 0; i < str.mStringLength; ++i)
    {
        mStringContent[i] = str.mStringContent[i];
    }

    mStringLength = str.mStringLength;

    return *this;
}

MyString &MyString::Assign(const char *str)
{
    int length = strlen(str);

    if (length > mMemoryCapacity)
    {
        delete[] mStringContent;

        mStringContent = new char[length];
        mMemoryCapacity = length;
    }

    for (int i = 0; i < length; ++i)
    {
        mStringContent[i] = str[i];
    }

    mStringLength = length;

    return *this;
}

void MyString::Reserve(int size)
{
    if (size > mMemoryCapacity)
    {
        char *prev_string_content = mStringContent;

        mStringContent = new char[size];
        mMemoryCapacity = size;

        for (int i = 0; i != mStringLength; ++i)
        {
            mStringContent[i] = prev_string_content[i];
        }

        delete[] prev_string_content;
    }
}

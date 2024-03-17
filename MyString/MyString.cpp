#include <iostream>
#include <cstring>
#include "MyString.h"

MyString::MyString(const int capacity)
{
    mStringContent = new char[capacity];
    mStringLength = 0;
    mMemoryCapacity = capacity;
}

MyString::MyString(const char c)
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

char MyString::At(const int i) const
{
    if (i >= mStringLength || i < 0)
    {
        return NULL;
    }
    else
    {
        return mStringContent[i];
    }
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

void MyString::Reserve(const int size)
{
    if (size > mMemoryCapacity)
    {
        char *prevStringContent = mStringContent;

        mStringContent = new char[size];
        mMemoryCapacity = size;

        for (int i = 0; i != mStringLength; ++i)
        {
            mStringContent[i] = prevStringContent[i];
        }

        delete[] prevStringContent;
    }
}

MyString &MyString::Insert(const int loc, const MyString &str)
{
    if (loc < 0 || loc >= str.mStringLength)
    {
        return *this;
    }

    int totalLength = str.mStringLength + mStringLength;
    if (totalLength > mMemoryCapacity)
    {
        if (mMemoryCapacity * 2 > totalLength)
        {
            mMemoryCapacity *= 2;
        }
        else
        {
            mMemoryCapacity = totalLength;
        }

        char* prevStringContent = mStringContent;
        mStringContent = new char[mMemoryCapacity];

        int i = 0;
        for (;i < loc; ++i)
        {
            mStringContent[i] = prevStringContent[i];
        }

        for (int j = 0; j < str.mStringLength; ++j)
        {
            mStringContent[i + j] = str.mStringContent[j];
        }

        for (; i < mStringLength; ++i)
        {
            mStringContent[str.mStringLength + i] = prevStringContent[i];
        }

        delete[] prevStringContent;
    }
    else
    {
        for (int i  = mStringLength - 1; i >= loc; --i)
        {
            mStringContent[str.mStringLength + i] = mStringContent[i];
        }

        for (int i = 0 ; i < str.mStringLength; ++i)
        {
            mStringContent[i + loc] = str.mStringContent[i];
        }
    }

    mStringLength = totalLength;
    return *this;
}

MyString &MyString::Insert(const int loc, const char *str)
{
    MyString temp(str);
    return Insert(loc, temp);
}

MyString &MyString::Insert(const int loc, const char c)
{
    MyString temp(c);
    return Insert(loc, temp);
}

int MyString::Compare(const MyString &str)
{
    // it performs (*this) - (str) and returns -1, 0, or 1.
    // 1 means (*this) comes later in dictionary, 0 means they are the same
    // -1 means (*this) comes first in dictionary

    for (int i = 0; i < std::min(mStringLength, str.mStringLength); ++i)
    {
        if (mStringContent[i] > str.mStringContent[i])
        {
            return 1;
        }
        else if (mStringContent[i] < str.mStringContent[i])
        {
            return -1;
        }
    }

    if (mStringLength == str.mStringLength)
    {
        return 0;
    }
    else if (mStringLength > str.mStringLength)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

bool MyString::operator==(MyString &str)
{
    return !Compare(str);
}
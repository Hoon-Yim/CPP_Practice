#ifndef CPP_PRACTICE_MYSTRING_H
#define CPP_PRACTICE_MYSTRING_H


class MyString {
private:
    char *mStringContent;
    int mStringLength;
    int mMemoryCapacity;

public:
    MyString(char c);
    MyString(const char *str);
    MyString(const MyString &str);

    MyString& Assign(const MyString &str);
    MyString& Assign(const char* str);
    void Reserve(int size);

    int Length() const;
    int Capacity() const;

    void Print() const;
    void Println() const;

    ~MyString();
};


#endif //CPP_PRACTICE_MYSTRING_H

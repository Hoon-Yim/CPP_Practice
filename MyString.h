#ifndef CPP_PRACTICE_MYSTRING_H
#define CPP_PRACTICE_MYSTRING_H


class MyString {
private:
    char *mStringContent;
    int mStringLength;
    int mMemoryCapacity;

public:
    MyString(const char c);
    MyString(const char *str);
    MyString(const MyString &str);

    MyString& Assign(const MyString &str);
    MyString& Assign(const char* str);
    MyString& Insert(const int loc, const MyString &str);
    MyString& Insert(const int loc, const char *str);
    MyString& Insert(const int loc, const char c);
    void Reserve(const int size);

    int Length() const;
    int Capacity() const;
    char At(const int i) const;

    void Print() const;
    void Println() const;

    ~MyString();
};


#endif //CPP_PRACTICE_MYSTRING_H

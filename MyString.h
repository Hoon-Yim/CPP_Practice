#ifndef CPP_PRACTICE_MYSTRING_H
#define CPP_PRACTICE_MYSTRING_H


class MyString {
private:
    char *mStringContent;
    int mStringLength;

public:
    MyString(char c);
    MyString(const char *str);
    MyString(const MyString &str);

    int Length() const;

    void Print() const;
    void Println() const;

    ~MyString();
};


#endif //CPP_PRACTICE_MYSTRING_H

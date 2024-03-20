#ifndef CPP_PRACTICE_COMPLEX_H
#define CPP_PRACTICE_COMPLEX_H


class Complex
{
private:
    double mReal, mImaginary;

public:
    Complex(double real, double imaginary) : mReal(real), mImaginary(imaginary) {}
    Complex(const Complex &c) : mReal(c.mReal), mImaginary(c.mImaginary) {}

    Complex operator+(const Complex &c) const;
    Complex operator-(const Complex &c) const;
    Complex operator*(const Complex &c) const;
    Complex operator/(const Complex &c) const;

    Complex& operator=(const Complex &c);
    Complex& operator+=(const Complex &c);
    Complex& operator-=(const Complex &c);
    Complex& operator*=(const Complex &c);
    Complex& operator/=(const Complex &c);

    void Println() const;
};


#endif //CPP_PRACTICE_COMPLEX_H

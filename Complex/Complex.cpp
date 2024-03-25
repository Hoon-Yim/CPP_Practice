#include <iostream>
#include "Complex.h"

Complex Complex::operator+(const Complex &c) const
{
    Complex temp(mReal + c.mReal, mImaginary + c.mImaginary);
    return temp;
}

Complex Complex::operator-(const Complex &c) const
{
    Complex temp(mReal - c.mReal, mImaginary - c.mImaginary);
    return temp;
}

Complex Complex::operator*(const Complex &c) const
{
    Complex temp(mReal * c.mReal - mImaginary * c.mImaginary,
                 mReal * c.mImaginary + mImaginary * c.mReal);
    return temp;
}

Complex Complex::operator/(const Complex &c) const
{
    Complex temp(
            (mReal * c.mReal + mImaginary * c.mImaginary) / (c.mReal * c.mReal + c.mImaginary * c.mImaginary),
            (mImaginary * c.mReal - mReal * c.mImaginary) / (c.mReal * c.mReal + c.mImaginary * c.mImaginary));
    return temp;
}

Complex& Complex::operator=(const Complex &c)
{
    mReal = c.mReal;
    mImaginary = c.mImaginary;

    return *this;
}

Complex& Complex::operator+=(const Complex &c)
{
    (*this) = (*this) + c;
    return *this;
}

Complex& Complex::operator-=(const Complex &c)
{
    (*this) = (*this) - c;
    return *this;
}

Complex& Complex::operator*=(const Complex &c)
{
    (*this) = (*this) * c;
    return *this;
}

Complex& Complex::operator/=(const Complex &c)
{
    (*this) = (*this) / c;
    return *this;
}

void Complex::Println() const
{
    std::cout << "( " << mReal << " , " << mImaginary << " ) " << std::endl;
}
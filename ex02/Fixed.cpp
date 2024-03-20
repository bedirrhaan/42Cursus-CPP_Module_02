#include "Fixed.hpp"

Fixed::Fixed()
{
    setRawBits(0);
}

Fixed::Fixed(const Fixed& other)
{
    setRawBits(other.getRawBits());
}

Fixed::Fixed(const int num)
{
    this->integerValue = num * static_cast<int>(pow(2,this->staticInteger));
}

Fixed::Fixed(const float num)
{
    this->integerValue = roundf(num * pow(2,this->staticInteger));
}

Fixed::~Fixed()
{

}

Fixed&  Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        setRawBits(other.getRawBits());
    return *this;
}
Fixed  Fixed::operator+(const Fixed& other) const
{
    return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed  Fixed::operator/(const Fixed& other) const
{
    return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed   Fixed::operator-(const Fixed& other) const
{
    return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed   Fixed::operator*(const Fixed& other) const
{
    return (Fixed(this->toFloat() * other.toFloat()));
}

bool    Fixed::operator>(const Fixed& other) const
{
    return (this->integerValue > other.integerValue);
}

bool    Fixed::operator<(const Fixed& other) const
{
    return (this->integerValue < other.integerValue);
}

bool    Fixed::operator==(const Fixed& other) const
{
    return (this->integerValue == other.integerValue);
}

bool    Fixed::operator!=(const Fixed& other) const
{
    return (this->integerValue != other.integerValue);
}

bool    Fixed::operator>=(const Fixed& other) const
{
    return (this->integerValue >= other.integerValue);
}

bool    Fixed::operator<=(const Fixed& other) const
{
    return (this->integerValue <= other.integerValue);
}

Fixed&   Fixed::operator++(void)
{
    this->integerValue++;
    return (*this);
}

Fixed  Fixed::operator++(int)
{
    Fixed   temp(*this);
    this->integerValue++;
    return (temp);
}

Fixed&  Fixed::operator--(void)
{
    this->integerValue--;
    return (*this);
}

Fixed   Fixed::operator--(int)
{
    Fixed   temp(*this);
    this->integerValue--;
    return (*this);
}

Fixed&   Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b ? a : b);
}   

Fixed&  Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b ? a : b);
}

int Fixed::toInt(void) const
{
    return (this->integerValue / static_cast<int>(pow(2, this->staticInteger)));
}

float   Fixed::toFloat(void) const
{
    return (this->integerValue / pow(2, this->staticInteger));
}

int Fixed::getRawBits(void) const
{
    return (integerValue);
}

void    Fixed::setRawBits(const int raw)
{
    integerValue = raw;
}

std::ostream&   operator<<(std::ostream& os, const Fixed& other)
{
    os << other.toFloat();
    return (os);
}   

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default Constructor Called" << std::endl;
    setRawBits(0);
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy Constructor Called" << std::endl;
    setRawBits(other.getRawBits());
}

Fixed::Fixed(const int num)
{
    std::cout << "Int constructor called" << std::endl;
    this->integerValue = num * static_cast<int>(pow(2,this->staticInteger));
}

Fixed::Fixed(const float num)
{
    std::cout << "Float constructor called" << std::endl;
    this->integerValue = roundf(num * pow(2,this->staticInteger));
}

Fixed::~Fixed()
{
    std::cout << "Destructor Called" << std::endl;
}

Fixed&  Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy Assigment Operator Called" << std::endl;
    if (this != &other)
        setRawBits(other.getRawBits());
    return *this;
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


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

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member constructor called" << std::endl;
    return (integerValue);
}

void    Fixed::setRawBits(const int raw)
{
    integerValue = raw;
}
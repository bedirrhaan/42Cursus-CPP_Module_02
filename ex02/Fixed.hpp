#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
    private:
        static const int    staticInteger = 8;
        int                 integerValue;
    public:
        // Constructor && Destructor
        Fixed();
        Fixed(const int num);
        Fixed(const float num);
        Fixed(const Fixed& other);
        ~Fixed();

        // Arithmetic Operators
        Fixed   operator+(const Fixed& other) const;
        Fixed   operator/(const Fixed& other) const;
        Fixed   operator-(const Fixed& other) const;
        Fixed   operator*(const Fixed& other) const;
        Fixed   &operator=(const Fixed& other);

        Fixed   &operator++(void);
        Fixed   operator++(int);
        Fixed   &operator--(void);
        Fixed   operator--(int);

        static  Fixed&  min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static  Fixed&  max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);

        // Comparison Operators
        bool    operator>(const Fixed& other) const;
        bool    operator<(const Fixed& other) const;
        bool    operator==(const Fixed& other) const;
        bool    operator!=(const Fixed& other) const;
        bool    operator>=(const Fixed& other) const;
        bool    operator<=(const Fixed& other) const;

        // Conversion
        int     toInt(void) const;
        float   toFloat(void) const;

        // Getters && Setters
        int     getRawBits(void) const;
        void    setRawBits(const int raw);
};

std::ostream&   operator<<(std::ostream& os, const Fixed& fixed);

#endif
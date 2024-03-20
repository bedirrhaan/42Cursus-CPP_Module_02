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
        Fixed();
        Fixed(const int num);
        Fixed(const float num);
        Fixed(const Fixed& other);
        ~Fixed();
        Fixed   &operator=(const Fixed& other);

        int     toInt(void) const;
        float   toFloat(void) const;
        int     getRawBits(void) const;
        void    setRawBits(const int raw);
};

std::ostream&   operator<<(std::ostream& os, const Fixed& fixed);

#endif
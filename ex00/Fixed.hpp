#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
    private:
        static const int    staticInteger;
        int                 integerValue;
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed& other);
        Fixed   &operator=(const Fixed& other);

        int     getRawBits(void) const;
        void    setRawBits(const int raw);
};

#endif
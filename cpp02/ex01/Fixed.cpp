#include "Fixed.hpp"

Fixed::Fixed( void ) 
{
	std::cout << "Default constructor called" << std::endl;
	fixed = 0;
}

Fixed::Fixed( const Fixed& obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::Fixed( const int value )
{
	fixed = value;
	fixed <<= frac_bits;
}

Fixed::Fixed( const float number )
{
	int frac = 1 / (number - (int)number);
	std::cout << 1 / (number - (int)number) << std::endl;
	fixed = (int)number << frac_bits;
	for (int i = 31; i >= 0; i--)
	{
		std::cout << ((fixed >> i) & 1); 
	}
	std::cout << frac << std::endl;
	fixed |= frac & 0xFF;
	for (int i = 31; i >= 0; i--)
	{
		std::cout << ((fixed >> i) & 1); 
	}
	std::cout << std::endl;
	
}

Fixed&	Fixed::operator= (const Fixed& obj)
{
	this->fixed = obj.fixed;
	return *this;
}

Fixed::~Fixed() 
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixed);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	fixed = raw;
}

float	Fixed::toFloat( void ) const
{
	return ((fixed >> frac_bits) * (1 + (float)1 / (fixed & 0xFF)));
}

int		Fixed::toInt( void ) const
{
	return (fixed >> frac_bits);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();\
	return (os);
}

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
	fixed = roundf(number * (1 << frac_bits));
}

Fixed&	Fixed::operator= (const Fixed& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
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

float Fixed::toFloat() const
{
	return ((float)fixed / (1 << frac_bits));
}

int		Fixed::toInt( void ) const
{
	return (fixed >> frac_bits);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}

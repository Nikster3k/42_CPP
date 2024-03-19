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

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int	fixed;
	static const int	frac_bits = 8;
public:
	Fixed( void );
	Fixed( const Fixed& obj);
	Fixed&	operator= (const Fixed& obj);
	~Fixed();

	int		getRawBits( void ) const;
	void	setRawBits( int const raw);
};

#endif //!FIXED_HPP

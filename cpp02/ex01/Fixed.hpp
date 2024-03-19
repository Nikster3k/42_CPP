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
	Fixed( const int value );
	Fixed( const float number );
	Fixed&	operator= (const Fixed& obj);
	~Fixed();

	int		getRawBits( void ) const;
	void	setRawBits( int const raw);
	float	toFloat( void ) const;
	int		toInt( void ) const;
	friend std::ostream&	operator<<( std::ostream& os , const Fixed& obj);
};

#endif //!FIXED_HPP
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

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

	bool operator< ( const Fixed& other) const;
	bool operator> ( const Fixed& other) const;
	bool operator<= ( const Fixed& other) const;
	bool operator>= ( const Fixed& other) const;
	bool operator!= ( const Fixed& other) const;
	bool operator== ( const Fixed& other) const;

	Fixed operator+ ( const Fixed& other ) const;
	Fixed operator- ( const Fixed& other ) const;
	Fixed operator* ( const Fixed& other ) const;
	Fixed operator/ ( const Fixed& other ) const;
	Fixed operator++ ( int );
	Fixed operator++ ( void );
	Fixed operator-- ( int );
	Fixed operator-- ( void );

	static Fixed&	min(Fixed& lhs, Fixed& rhs);
	static const Fixed&	min(const Fixed& lhs, const Fixed& rhs);
	static Fixed&	max(Fixed& lhs, Fixed& rhs);
	static const Fixed&	max(const Fixed& lhs, const Fixed& rhs);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw);
	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream&	operator<<( std::ostream& os , const Fixed& obj);

#endif //!FIXED_HPP

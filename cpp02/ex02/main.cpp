#include <iostream>
#include "Fixed.hpp"

int main( void ) 
{
	std::cout << "==Given tests==" << std::endl;
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	std::cout << "\n==Extra tests==\n" << std::endl;
	{
		Fixed c(10.5f);
		Fixed d(2.5f);
		std::cout << c << std::endl; // Output: 10.5
		std::cout << d << std::endl; // Output: 2.5

		Fixed e = c + d;
		std::cout << e << std::endl; // Output: 13

		Fixed f = c - d;
		std::cout << f << std::endl; // Output: 8

		Fixed g = c * d;
		std::cout << g << std::endl; // Output: 26.25

		Fixed h = c / d;
		std::cout << h << std::endl; // Output: 4.2

		bool isEqual = (c == d);
		std::cout << isEqual << std::endl; // Output: 0 (false)

		bool isNotEqual = (c != d);
		std::cout << isNotEqual << std::endl; // Output: 1 (true)

		bool isGreaterThan = (c > d);
		std::cout << isGreaterThan << std::endl; // Output: 1 (true)

		bool isLessThan = (c < d);
		std::cout << isLessThan << std::endl; // Output: 0 (false)
	}
	return 0;
}

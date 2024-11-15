#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <iostream>
class Point
{
private:
	const Fixed	x;
	const Fixed	y;
public:
	Point( void );
	Point( const float a_fX, const float a_fY );
	Point( const Fixed a_cX, const Fixed a_cY );
	Point( const Point& obj);
	Point&	operator= (const Point& obj);
	~Point();

	float	sqrLength( void );
	float	dot( const Point& other );
	float	crossProduct( const Point& other ) const;

	Point	operator+ (const Point& obj) const;
	Point	operator- (const Point& obj) const;

};

bool bsp( Point const a, Point const b, Point const c, Point const point );

#endif  //!POINT_HPP

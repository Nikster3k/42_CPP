#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float a_fX, const float a_fY) : x(a_fX), y(a_fY) {}

Point::Point(const Fixed a_cX, const Fixed a_cY) : x(a_cX), y(a_cY) {}

Point::Point(const Point& obj) : x(obj.x), y(obj.y) {}

Point&	Point::operator= (const Point& obj)
{
	//only const member variables
	//nothing to do here :)
	(void)obj;
	return (*this);
}

Point::~Point() {}

Point	Point::operator+ (const Point& obj) const
{
	return (Point(x + obj.x, y + obj.y));
}

Point	Point::operator- (const Point& obj) const
{
	return (Point(x - obj.x, y - obj.y));
}

float	Point::crossProduct(const Point& other) const
{
	return ((this->x * other.y) - (this->y * other.x)).toFloat();
}

float	Point::sqrLength(void)
{
	return((x * x + y * y).toFloat());
}

float	Point::dot(const Point& other)
{
	return((x * other.x + y * other.y).toFloat());
}

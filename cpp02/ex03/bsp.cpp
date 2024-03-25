#include "Point.hpp"

bool	isOnEdge(const Point a, const Point b, const Point point)
{
	Point	AB = b - a;
	Point	PA = point - a;
	Point	PB = point - b;

	return (AB.sqrLength() == (PA.sqrLength() + PB.sqrLength()));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point	AB = b - a;
	Point	AC = c - a;
	Point	CB = b - c;
	Point	PA = point - a;
	Point	PB = point - b;
	Point	PC = point - c;

	Fixed	areaWhole = 0.5f * std::abs(AB.crossProduct(AC));
	Fixed	area1 = 0.5f * std::abs(PA.crossProduct(PB));
	Fixed	area2 = 0.5f * std::abs(PB.crossProduct(PC));
	Fixed	area3 = 0.5f * std::abs(PC.crossProduct(PA));
	if ((area1 + area2 + area3) != areaWhole)
		return (false);
	if (isOnEdge(a, b, point) || isOnEdge(b, c, point) || isOnEdge(c, a, point))
		return (false);
	return ((area1 + area2 + area3) == areaWhole);
}

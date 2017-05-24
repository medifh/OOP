#include "Shapes.h"

template < typename T >
Point RandPoint()
{
	Point exemp(rand(), rand());
	return exemp;
}

template < typename T >
Rect RandRect()
{
	Point a(rand(), rand());
	Point b(rand(), rand());
	Rect exemp(a, b);
	return exemp;
}

template < typename T >
Square RandSquare()
{
	Point a(rand(), rand());
	Point b(rand(), rand());
	Square exemp(a, b, rand());
	return exemp;
}

template < typename T >
Circle RandCircle()
{
	Point a(rand(), rand());
	Circle exemp(a, rand());
	return exemp;
}
template < typename T >
Polygon RandPolygon()
{
	Point a(rand(), rand());
	Polygon exemp(a);
	for (int i = 0; i < (rand()) % 10; i++)
	{
		Point b(rand(), rand());
		exemp.AddPoint(b);
	}
	return exemp;
}

template < typename T >
Polyline RandPolyline()
{
	Point a(rand(), rand());
	Polyline exemp(a);
	for (int i = 0; i < (rand()) % 10; i++)
	{
		Point b(rand(), rand());
		exemp.AddPoint(b);
	}
	return exemp;
}


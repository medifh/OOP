#include "Shapes.h"

template < typename T >
Point RandPoint()
{
	Point instance(rand(), rand());
	return instance;
}

template < typename T >
Rect RandRect()
{
	Point a(rand(), rand());
	Point b(rand(), rand());
	Rect instance(a, b);
	return instance;
}

template < typename T >
Square RandSquare()
{
	Point a(rand(), rand());
	Point b(rand(), rand());
	Square instance(a, b, rand());
	return instance;
}

template < typename T >
Circle RandCircle()
{
	Point a(rand(), rand());
	Circle instance(a, rand());
	return instance;
}
template < typename T >
Polygon RandPolygon()
{
	Point a(rand(), rand());
	Polygon instance(a);
	for (int i = 0; i < (rand()) % 10; i++)
	{
		Point b(rand(), rand());
		instance.AddPoint(b);
	}
	return instance;
}

template < typename T >
Polyline RandPolyline()
{
	Point a(rand(), rand());
	Polyline instance(a);
	for (int i = 0; i < (rand()) % 10; i++)
	{
		Point b(rand(), rand());
		instance.AddPoint(b);
	}
	return instance;
}


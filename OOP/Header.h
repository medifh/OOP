#include "Shapes.h"
#include <ctime>

Point RandPoint()
{
	srand(time(0));
	Point exemp(rand(), rand());
	return exemp;
}

Rect RandRect()
{
	srand(time(0));
	Point a(rand(), rand());
	Point b(rand(), rand());
	Rect exemp(a, b);
	return exemp;
}

Square RandSquare()
{
	srand(time(0));
	Point a(rand(), rand());
	Point b(rand(), rand());
	Square exemp(a, b, rand());
	return exemp;
}

Circle RandCircle()
{
	srand(time(0));
	Point a(rand(), rand());
	Circle exemp(a, rand());
	return exemp;
}

Polygon RandPolygon()
{
	srand(time(0));
	Point a(rand(), rand());
	Polygon exemp(a);
	for (int i = 0; i < (rand()) % 10; i++)
	{
		Point b(rand(), rand());
		exemp.AddPoint(b);
	}
	return exemp;
}

Polyline RandPolyline()
{
	srand(time(0));
	Point a(rand(), rand());
	Polyline exemp(a);
	for (int i = 0; i < (rand()) % 10; i++)
	{
		Point b(rand(), rand());
		exemp.AddPoint(b);
	}
	return exemp;
}


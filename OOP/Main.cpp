
#include "Factory.cpp"
#include <ctime>

void main()
{
	srand((unsigned int)time(0));
	std::string b;
	Point a(12, 3);
	Point a1(21, 4);
	Circle c(a, 2);
	Rect d(a, a1);
	Square x;
	Polyline y;
	Polygon z;
	y.AddPoint(a);
	z.AddPoint(a);
	y.AddPoint(a1);
	z.AddPoint(a1);
	std::cout << y.Print() << "\n" << z.Print() << "\n" << d.Print();
	/*
	Conteiner<Shape> figures;
	Point sadf = RandPoint<int>();
	
	for (int i = 0; i < 20; i++)
	{
		int r = rand() % 6;
		if (r == 0) figures.PutHead(RandPoint<int>());
		if (r == 1) figures.PutHead(RandRect<int>());
		if (r == 2) figures.PutHead(RandSquare<int>());
		if (r == 3) figures.PutHead(RandCircle<int>());
		if (r == 4) figures.PutHead(RandPolygon<int>());
		if (r == 5) figures.PutHead(RandPolyline<int>());
	}*/
	Rect cc = RandRect<int>();
	std::cout << "\n\n" << cc.Print();
	system("pause");
}
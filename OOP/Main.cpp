
#include "Factory.cpp"
#include <ctime>



int main()
{
	//	Shape::RefreshCount();
	srand((unsigned int)time(0));

	Container<Shape*> figures;
	for (int i = 0; i < 20; i++)
	{
		int r = rand() % 6;
		if (r == 0) {
			Point * a = new Point(RandPoint<int>());
			figures.PutHead(a);
		}
		if (r == 1) {
			Rect * a = new Rect(RandRect<int>());
			figures.PutHead(a);
		}
		if (r == 2) {
			Square * a = new Square(RandSquare<int>());
			figures.PutHead(a);
		}
		if (r == 3) {
			Circle * a = new Circle(RandCircle<int>());
			figures.PutHead(a);
		}
		if (r == 4) {
			Polygon * a = new Polygon(RandPolygon<int>());
			figures.PutHead(a);
		}
		if (r == 5) {
			Polyline * a = new Polyline(RandPolyline<int>());
			figures.PutHead(a);
		}
	}
	std::string error_info;
	try
	{
		if (figures.IsEmpty()) throw error_info = "container is empty in first for";
		for (int i = 0; i < 20; i++)
		{
			std::cout << "\n\n" << (figures.GetElement(i)) -> Print();
		}
	}
	catch (const std::string &error_info) {
		std::cout << error_info;
		system( "pause" );
		return 1;
	}

	figures.Clearn();

	try
	{
		if (figures.IsEmpty()) throw error_info = "container is empty in second for";
		for (int i = 0; i < 20; i++)
		{
			std::cout << "\n\n" << (figures.GetElement(i)) -> Print();
		}
	}
	catch (const std::string &error_info) {
		std::cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << error_info << "\n";
		system("pause");
		return 2;
	}

	//std::cout << "\n\n" << Shape::GetCount();
	system("pause");
	return 0;
}
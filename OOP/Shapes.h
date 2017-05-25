#include "Base.h"
#include "Container.h"

const double pi = 3.14159265358979323846;

class Shape : public Printable
{

protected:
	//static
	int m_counter;

public:
	/*
	static int GetCount ()
	{
		return m_counter;
	}

	static void RefreshCount()
	{
		m_counter=0;
	}
	*/
	Shape() { }
	~Shape() { }
private:
};



class Point : public Named, public Shape
{

private:
	double m_x, m_y;

public:
	Point()
	{
		this -> Putname("Point ");
		m_x = 0;
		m_y = 0;
		Shape::m_counter ++;
	}

	~Point() { Shape::m_counter --; }

	Point(double x, double y)
	{
		this -> Putname("Point ");
		m_x = x;
		m_y = y;
		Shape::m_counter ++;
	}

	Point coords(double x, double y)
	{
		m_x = x;
		m_y = y;
		return * this;
	}

	std::string Print()
	{
		std::string info;
		info = this->Getname();
		info += "x = " + std::to_string((long double)m_x) + " y = " + std::to_string((long double)m_y);
		return info;
	}

	Point(const Point & orig)
	{
		this -> m_x = orig.m_x;
		this -> m_y = orig.m_y;
	}

	double x()
	{
		return m_x;
	}

	double y()
	{
		return m_y;
	}

};

class Circle : public Named, public Shape
{
private:
	Point m_centre;
	int m_radius;

public:
	Circle()
	{
		Shape::m_counter ++;
		this -> Putname("Circle ");
		m_centre.coords(0, 0);
		m_radius = 0;
	}

	~Circle() { Shape::m_counter --; }

	Circle(Point o, int rad)
	{
		Shape::m_counter ++;
		this -> Putname("Circle ");
		m_centre = o;
		m_radius = rad;
	}

	double Area()
	{
		return m_radius * m_radius * pi;
	}

	std::string Print()
	{
		std::string info;
		info = this -> Getname() + m_centre.Print() + " radius= " + std::to_string((long double)m_radius);
		info += " Area: " + std::to_string((long double)this->Area());
		return info;
	}

	Circle(const Circle & orig)
	{
		this -> m_centre = orig.m_centre;
		this -> m_radius = orig.m_radius;
	}

};

class Rect : public Named, public Shape
{
private:
	Point m_botleft;
	Point m_upright;

public:
	Rect()
	{
		Shape::m_counter++;
		this -> Putname("Rectangle ");
		m_botleft.coords(0, 0);
		m_upright.coords(0, 0);
	}

	Rect(Point a_point, Point b_point)
	{
		Shape::m_counter++;
		this -> Putname("Rectangle ");
		m_botleft = a_point;
		m_upright = b_point;
	}

	~Rect() { Shape::m_counter--; }

	double Area()
	{
		return abs((m_botleft.x() - m_upright.x()) * (m_botleft.y() - m_upright.y()));
	}

	std::string Print()
	{
		std::string info;
		info = this->Getname() + " first dot: " + m_botleft.Print() + " second dot: " + m_upright.Print();
		info += " Area: " + std::to_string((long double)this->Area());
		return info;
	}

	Rect(const Rect & orig)
	{
		this -> m_botleft = orig.m_botleft;
		this -> m_upright = orig.m_upright;
	}

};

class Square : public Rect
{
private:
	Point m_botleft;
	Point m_upright;
	double m_length;

public:

	Square()
	{
		Shape::m_counter++;
		this -> Putname("Rectangle ");
		m_botleft.coords(0, 0);
		m_upright.coords(0, 0);
		m_length = 0;
	}

	Square(Point a_point, Point b_point, double length)
	{
		Shape::m_counter++;
		this -> Putname("Rectangle ");
		m_botleft = a_point;
		m_upright = b_point;
		m_length = length;
	}

	~Square() { Shape::m_counter--; }

	double Area()
	{
		return m_length * m_length;
	}

	std::string Print()
	{
		std::string info;
		info = this -> Getname() + " first dot: " + m_botleft.Print() + " second dot: " + m_upright.Print();
		info += " length: " + std::to_string((long double)m_length);
		info += " Area: " + std::to_string((long double)this->Area());
		return info;
	}

	Square(const Square & orig)
	{
		this -> m_botleft = orig.m_botleft;
		this -> m_upright = orig.m_upright;
		this -> m_length = orig.m_length;
	}

};

class Polygon;

class Polyline :public Named, public Shape
{
private:
	Container <Point>  m_dots;

public:
	Polyline()
	{
		Shape::m_counter++;
		this -> Putname("Polyline ");
		Container <Point>  m_dots;
	}

	Polyline(Point firstdot)
	{
		Shape::m_counter++;
		this -> Putname("Polyline ");
		m_dots.PutHead(firstdot);
	}

	~Polyline() { Shape::m_counter--; }

	double Length()
	{
		double len = 0;
		Point a;
		if (m_dots.GetQuanity()) a = m_dots.GetElement(0);
		for (int i = 1; i < m_dots.GetQuanity(); i++)
		{
			Point b = m_dots.GetElement(i);
			len += sqrt((a.x() - b.x()) * (a.x() - b.x()) + (a.y() - b.y()) * (a.y() - b.y()));
		}
		return len;
	}

	std::string Print()
	{
		std::string info;
		info = this -> Getname() + " dots: ";
		for (int i = 0; i < m_dots.GetQuanity(); i++)
		{
			Point b = m_dots.GetElement(i);
			info += "dot number " + std::to_string((long double)i) + ": " + b.Print() + " ";
		}
		info += " length: " + std::to_string((long double) this->Length());
		return info;
	}

	Polyline(const Polyline & orig)
	{
		this -> m_dots = orig.m_dots;
	}

	void AddPoint(Point const & newdot)
	{
		m_dots.PutHead(newdot);
	}

	friend Polygon;

};

class Polygon : public Polyline
{
private:

public:

	Polygon()
	{
		Shape::m_counter++;
		this -> Putname("Polygon ");
		Container <Point>  m_dots;
	}

	Polygon(Point firstdot)
	{
		Shape::m_counter++;
		this -> Putname("Polygon ");
		m_dots.PutHead(firstdot);
		m_dots.PutTail(firstdot);
	}

	std::string Print()
	{
		std::string info;
		info = this->Getname() + " dots: ";
		for (int i = 0; i < m_dots.GetQuanity(); i ++)
		{
			Point b = m_dots.GetElement(i);
			info += "dot number " + std::to_string((long double)i) + ": " + b.Print() + " ";
		}
		info += " Perimetr: " + std::to_string((long double) this->Length());
		return info;
	}

	Polygon(const Polygon & orig)
	{
		this -> m_dots = orig.m_dots;
	}

	void AddPoint(Point const & newdot)
	{
		if (m_dots.IsEmpty()) m_dots.PutHead(newdot);
		else
		{
			Point a =  m_dots.GetHead();
			m_dots.DelHead();
			if (m_dots.IsEmpty())
			{
				m_dots.PutHead(newdot);
				m_dots.PutHead(a);
				m_dots.PutTail(a);
			}
			else
			{
				m_dots.PutHead(newdot);
				m_dots.PutHead(m_dots.GetTail());
			}
		}
		//For polygon tail=head
	}

};

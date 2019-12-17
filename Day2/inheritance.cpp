#include <iostream>
#include <vector>

using namespace std;

class Shape
{
public:
	Shape(double w, double h) : width(w), height(h){}
	virtual double area() = 0;
protected:
	double width;
	double height;
};

class Rectangle : public Shape
{
public:
	Rectangle(double w, double h) : Shape(w, h) {}
	double area()
	{
		return width * height;
	}
};

class Triangle : public Shape
{
public:
	Triangle(double w, double h) : Shape(w, h) {}
	double area()
	{
		return width * height / 2;
	}
};

void print_area(Shape* s)
{
	cout << s->area() << endl;
}

int main()
{
	Rectangle r1(10.4, 20.3);
	Rectangle r2(4.5, 17.2);
	Rectangle r3(14.1, 16.3);
	Triangle t1(10.4, 20.3);
	Triangle t2(4.5, 17.2);
	Triangle t3(14.1, 16.3);
	vector<Shape*> shapes{ &r1, &r2, &r3, &t1, &t2, &t3 };
	for (auto shape : shapes)
	{
		cout << shape->area() << endl;
	}
	


	return 0;
}
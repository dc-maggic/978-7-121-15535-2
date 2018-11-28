#ifndef PRACTISE15_21_H_INCLUDED
#define PRACTISE15_21_H_INCLUDED

class Figure {
public:
	virtual ~Figure() = default;
	Figure(double x, double y) :x(x), y(y) {}
protected:
	double x = 0.0, y = 0.0;
};
class Figure_2D :public Figure {
public:
	Figure_2D() = default;
	Figure_2D(double x, double y) :Figure(x, y) {}
	virtual double perimeter() const = 0;
	virtual double area() const = 0;
};
class Figure_3D :public Figure {
public:
	Figure_3D() = default;
	Figure_3D(double x, double y, double z) :Figure(x, y), z(z) {}
	virtual double area() const = 0;
	virtual double volume() const = 0;
protected:
	double z = 0.0;
};
class Rectangle :public Figure_2D{
public:
	Rectangle() = default;
	Rectangle(double x, double y) :Figure_2D(x, y) {}
	double perimeter() const override { return 2 * (x + y); }
	double area() const override { return x * y; }
};
class Circle :public Figure_2D {
public:
	Circle() = default;
	Circle(double r) :Figure_2D(r, 0.0) {}
	double perimeter() const override { return 2 * 3.14*x; }
	double area() const override { return 3.14*x*x; }
};
class Cuboid :public Figure_3D {
public:
	Cuboid() = default;
	Cuboid(double x, double y, double z) :Figure_3D(x, y, z) {}
	double area() const override { return 2 * x*y + 2 * y*z + 2 * z*x; }
	double volume() const override { return x * y*z; }
};
#endif PRACTISE15_21_H_INCLUDED
/*
Вам нужно реализовать базовый класс для геометрических фигур — Shape и два его наследника — Circle и Rectangle. 
У базового класса Shape нужно определить общий метод area(), который возвращает площадь геометрической фигуры, 
а в наследниках — реализовать этот метод. В комментариях к коду указано, какие параметры должны принимать 
конструкторы классов-наследников.

Требования к реализации: При реализации не нужно вводить или выводить что-либо. Реализовывать main не нужно.
*/

#include <cmath>
// Воспользуйтесь константой для пи - M_PI

// базовый класс для фигур
struct Shape
{
	Shape() {}

	virtual ~Shape() {};
	// метод area вычисляющий площадь фигуры
	virtual double area() {
		return 0.0;
	}
};

// класс для круга
struct Circle : public Shape
{
	// конструктор от радиуса
	Circle(double radius) : radius_(radius) {}
	// реализация метода area
	virtual double area()
	{
		return M_PI * radius_ * radius_;
	}
private:
	double radius_;
};

// класс прямоугольника
struct Rectangle : public Shape
{
	// конструктор от ширины и высоты
	Rectangle(double a, double b) : a_(a), b_(b) {}
	// реализация метода area
	virtual double area()
	{
		return a_ * b_;
	}

private:
	double a_;
	double b_;
};

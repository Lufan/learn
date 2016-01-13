/*
��� ����� ����������� ������� ����� ��� �������������� ����� � Shape � ��� ��� ���������� � Circle � Rectangle. 
� �������� ������ Shape ����� ���������� ����� ����� area(), ������� ���������� ������� �������������� ������, 
� � ����������� � ����������� ���� �����. � ������������ � ���� �������, ����� ��������� ������ ��������� 
������������ �������-�����������.

���������� � ����������: ��� ���������� �� ����� ������� ��� �������� ���-����. ������������� main �� �����.
*/

#include <cmath>
// �������������� ���������� ��� �� - M_PI

// ������� ����� ��� �����
struct Shape
{
	Shape() {}

	virtual ~Shape() {};
	// ����� area ����������� ������� ������
	virtual double area() {
		return 0.0;
	}
};

// ����� ��� �����
struct Circle : public Shape
{
	// ����������� �� �������
	Circle(double radius) : radius_(radius) {}
	// ���������� ������ area
	virtual double area()
	{
		return M_PI * radius_ * radius_;
	}
private:
	double radius_;
};

// ����� ��������������
struct Rectangle : public Shape
{
	// ����������� �� ������ � ������
	Rectangle(double a, double b) : a_(a), b_(b) {}
	// ���������� ������ area
	virtual double area()
	{
		return a_ * b_;
	}

private:
	double a_;
	double b_;
};

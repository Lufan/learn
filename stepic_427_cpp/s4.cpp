/*
���������� ��������� ����� Vector2D ����������� ������ �� ���������. ������ ������� ����� ������������ � ������ �� 
� �������� ����� x � y. ��������� �������� � ��� ��� ��������� �������.

��� ����� ������ ��� ����� ����������� ��������, ���������, ��������� �� ����� (����� � ������) � ��������� 
�� ���������/�����������. ��� ��������� ������ ���� ����������� ��� ������� �������. �������� ������ ���������� 
������������� �� �����.

����� ���� ����� ����������� ������������ �� Vector2D � ������ ��������� ����������. �.�. 
������ ��������� �������� ��������� ���:

Vector2D<int> v(1,2);

Vector2D<double> w(v);
���������� � ����������: ��� ���������� �� ����� ������� ��� �������� ���-����. ������������� main �� �����.
*/

// ��������� ����� Vector2D        
template <typename T>
struct Vector2D
{
	// ����������� ��-���������, �������������� ���������� ������
	Vector2D() : x(0), y(0) {}

	// ����������� �� x � y
	Vector2D(T x_, T y_) : x(x_), y(y_) {}

	// ����������� �� Vector2D � ������ ��������� ����������
	template <typename T2>
	Vector2D(T2 const& v) {
		x = v.x;
		y = v.y;
	}

	// ����
	T x;
	T y;
};

// �������� +
template <typename T>
Vector2D<T> operator+(Vector2D<T> a, Vector2D<T> b) {
	return Vector2D<T>(a.x + b.x, a.y + b.y);
}

// �������� -
template <typename T>
Vector2D<T> operator-(Vector2D<T> a, Vector2D<T> b) {
	return Vector2D<T>(a.x - b.x, a.y - b.y);
}

// �������� ��������� �� ����� �����
template <typename T>
Vector2D<T> operator*(T k, Vector2D<T> a) {
	return Vector2D<T>(a.x * k, a.y * k);
}

// �������� ��������� �� ����� ������
template <typename T>
Vector2D<T> operator*(Vector2D<T> a, T k) {
	return Vector2D<T>(a.x * k, a.y * k);
}
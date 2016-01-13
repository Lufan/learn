/*
Реализуйте шаблонный класс Vector2D описывающий вектор на плоскости. Вектор задаётся двумя координатами и хранит их 
в открытых полях x и y. Шаблонный параметр — это тип координат вектора.

Для этого класса вам нужно реализовать сложение, вычитание, умножение на число (слева и справа) и сравнение 
на равенство/неравенство. Все операторы должны быть реализованы как внешние функции. Короткие версии операторов 
реализовывать не нужно.

Кроме того нужно реализовать констуруктор от Vector2D с другим шаблонным параметром. Т.е. 
должен корректно работать следующий код:

Vector2D<int> v(1,2);

Vector2D<double> w(v);
Требования к реализации: При реализации не нужно вводить или выводить что-либо. Реализовывать main не нужно.
*/

// шаблонный класс Vector2D        
template <typename T>
struct Vector2D
{
	// конструктор по-умолчанию, инициализирует координаты нулями
	Vector2D() : x(0), y(0) {}

	// конструктор от x и y
	Vector2D(T x_, T y_) : x(x_), y(y_) {}

	// конструктор от Vector2D с другим шаблонным параметром
	template <typename T2>
	Vector2D(T2 const& v) {
		x = v.x;
		y = v.y;
	}

	// поля
	T x;
	T y;
};

// оператор +
template <typename T>
Vector2D<T> operator+(Vector2D<T> a, Vector2D<T> b) {
	return Vector2D<T>(a.x + b.x, a.y + b.y);
}

// оператор -
template <typename T>
Vector2D<T> operator-(Vector2D<T> a, Vector2D<T> b) {
	return Vector2D<T>(a.x - b.x, a.y - b.y);
}

// оператор умножения на число слева
template <typename T>
Vector2D<T> operator*(T k, Vector2D<T> a) {
	return Vector2D<T>(a.x * k, a.y * k);
}

// оператор умножения на число справа
template <typename T>
Vector2D<T> operator*(Vector2D<T> a, T k) {
	return Vector2D<T>(a.x * k, a.y * k);
}
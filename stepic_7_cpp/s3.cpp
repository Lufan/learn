/*
Реализуйте шаблонную версию класса Array. Список всех операций, которые должен поддерживать 
класс Array, приведен в шаблоне кода.
*/

#include <cstddef>

template <typename T>
class Array
{
public:
	// Список операций:
	//   конструктор класса, который создает
	//   Array размера size, заполненный значениями
	//   value типа T. Считайте что у типа T есть
	//   конструктор, который можно вызвать без
	//   без параметров, либо он ему не нужен.
	explicit Array(size_t size = 0, const T& value = T()) :
		_arr(new T[size]), _size(size) {
		for (size_t i = 0; i < _size; ++i) _arr[i] = value;
	}

	//   конструктор копирования, который создает
	//   копию параметра. Считайте, что для типа
	//   T определен оператор присваивания.
	Array(const Array<T> &other) {
		_size = other._size;
		_arr = new T[_size];
		for (size_t i = 0; i < _size; ++i) _arr[i] = other[i];
	}

	//   деструктор, если он вам необходим.
	~Array() {
		_size = 0;
		delete[] _arr;
		_arr = NULL;
	}

	//   оператор присваивания.
	Array& operator=(Array<T> &other) {
		if (this == &other) return *this;
		_size = other._size;
		delete[] _arr;
		_arr = new T[_size];
		for (size_t i = 0; i < _size; ++i) _arr[i] = other[i];
		return *this;
	}

	//   возвращает размер массива (количество
	//                              элементов).
	size_t size() const {
		return _size;
	}

	//   две версии оператора доступа по индексу.
	T& operator[](size_t index) {
		return _arr[index];
	}
	const T& operator[](size_t index) const {
		return _arr[index];
	}

private:
	T *_arr;
	size_t _size;
};
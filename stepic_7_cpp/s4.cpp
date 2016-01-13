/*
� ���������� ������ ��������������, ��� ��� ���� T ��������� �������� ������������ ��� �� ��� �� ����� 
(��������, ��� ����������� ����� �� �� �����). ��� �������� ��������� ������� ����������� (����� Array 
� �� ������) ������� ��������� �������������� ���������� � ����� ��������� ����������. ������� �������� 
������, ���������� ����� Array �� ��������� �� ��, ��� ��� ���� T ��������� �������� ������������. Hints: 
����������� placement new � ����� ����� ����������� (�������� ���� 3.4), ����� ��������� � ���������� �������, 
������������ ��������� ����������� ������ ����� � ������� new char[N * sizeof(T)], ��� N - ���������� ��������� �������.
*/

#include <cstddef>

template <typename T>
class Array
{
public:
	// ������ ��������:
	//   ����������� ������, ������� �������
	//   Array ������� size, ����������� ����������
	//   value ���� T. �������� ��� � ���� T ����
	//   �����������, ������� ����� ������� ���
	//   ��� ����������, ���� �� ��� �� �����.
	Array(size_t size, const T& value = T())
	{
		_size = size;
		size_t char_size = _size * sizeof(T);
		_arr = (T*)(new char[char_size]);
		for (size_t i = 0; i < _size; ++i) new (_arr + i) T(value);
	}

	//   ����������� ������, ������� ����� �������
	//   ��� ����������. ������ ��������� ������
	//   Array.
	Array() {
		_size = 0;
		_arr = new T[0];
	}

	//   ����������� �����������, ������� �������
	//   ����� ���������. ��� ���� T ��������
	//   ����������� �� ���������.
	Array(const Array<T> &other) {
		_size = other._size;
		size_t char_size = _size * sizeof(T);
		_arr = (T*)(new char[char_size]);
		for (size_t i = 0; i < _size; ++i) new (_arr + i) T(other[i]);
	}

	//   ����������, ���� �� ��� ���������.
	~Array() {
		for (size_t i = 0; i < _size; ++i) {
			(_arr + i)->~T();
			//delete (T*)(_arr + i);
		}
		_size = 0;
		delete[]((char*)_arr);
		_arr = NULL;
	}

	//   �������� ������������.
	Array& operator=(Array<T> &other) {
		if (this == &other) return *this;
		for (size_t i = 0; i < _size; ++i) {
			(_arr + i)->~T();
			//delete (_arr + i);
		}
		delete[](char*)_arr;
		_size = other._size;
		size_t char_size = _size * sizeof(T);
		_arr = (T*)(new char[char_size]);
		for (size_t i = 0; i < _size; ++i) new (_arr + i) T(other[i]);
		return *this;
	}

	//   ���������� ������ ������� (����������
	//                              ���������).
	size_t size() const {
		return _size;
	}

	//   ��� ������ ��������� ������� �� �������.
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
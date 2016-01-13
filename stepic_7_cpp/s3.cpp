/*
���������� ��������� ������ ������ Array. ������ ���� ��������, ������� ������ ������������ 
����� Array, �������� � ������� ����.
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
	explicit Array(size_t size = 0, const T& value = T()) :
		_arr(new T[size]), _size(size) {
		for (size_t i = 0; i < _size; ++i) _arr[i] = value;
	}

	//   ����������� �����������, ������� �������
	//   ����� ���������. ��������, ��� ��� ����
	//   T ��������� �������� ������������.
	Array(const Array<T> &other) {
		_size = other._size;
		_arr = new T[_size];
		for (size_t i = 0; i < _size; ++i) _arr[i] = other[i];
	}

	//   ����������, ���� �� ��� ���������.
	~Array() {
		_size = 0;
		delete[] _arr;
		_arr = NULL;
	}

	//   �������� ������������.
	Array& operator=(Array<T> &other) {
		if (this == &other) return *this;
		_size = other._size;
		delete[] _arr;
		_arr = new T[_size];
		for (size_t i = 0; i < _size; ++i) _arr[i] = other[i];
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
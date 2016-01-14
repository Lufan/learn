/*
В предыдущей версии предполагается, что для типа T определен оператор присваивания или он ему не нужен 
(например, для примитивных типов он не нужен). При создании шаблонных классов контейнеров (вроде Array 
и не только) разумно стараться минимизировать требования к типам шаблонных параметров. Поэтому усложним 
задачу, реализуйте класс Array не полагаясь на то, что для типа T определен оператор присваивания. Hints: 
используйте placement new и явный вызов деструктора (смотрите урок 3.4), чтобы создавать и уничтожать объекты, 
аллоцировать правильно выровненную память можно с помощью new char[N * sizeof(T)], где N - количество элементов массива.
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
	Array(size_t size, const T& value = T())
	{
		_size = size;
		size_t char_size = _size * sizeof(T);
		_arr = (T*)(new char[char_size]);
		for (size_t i = 0; i < _size; ++i) new (_arr + i) T(value);
	}

	//   конструктор класса, который можно вызвать
	//   без параметров. Должен создавать пустой
	//   Array.
	Array() {
		_size = 0;
		_arr = new T[0];
	}

	//   конструктор копирования, который создает
	//   копию параметра. Для типа T оператор
	//   присвивания не определен.
	Array(const Array<T> &other) {
		_size = other._size;
		size_t char_size = _size * sizeof(T);
		_arr = (T*)(new char[char_size]);
		for (size_t i = 0; i < _size; ++i) new (_arr + i) T(other[i]);
	}

	//   деструктор, если он вам необходим.
	~Array() {
		for (size_t i = 0; i < _size; ++i) {
			(_arr + i)->~T();
			//delete (T*)(_arr + i);
		}
		_size = 0;
		delete[]((char*)_arr);
		_arr = NULL;
	}

	//   оператор присваивания.
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
/*
В этой задаче вам требуется реализовать оператор [] для уже известного вам класса String. 
Однако на этот раз оператор должен реализовывать нестандартное поведение: оператор нужно 
реализовать таким образом, чтобы для объекта str класса String можно было писать str[i][j] 
и это выражение возвращало подстроку начинающуюся в позиции i (считая с 0) и заканчивающуюся в позиции j (не включая).

Например:

String const hello("hello");
String const hell = hello[0][4]; // теперь в hell хранится подстрока "hell"
String const ell  = hello[1][4]; // теперь в ell хранится подстрока "ell"

Обратите внимание, что i может равняться j, в этом случае результатом должна быть пустая 
строка. Гарантируется, что i никогда не будет больше j, и они не будут выходить за пределы длины строки.
Требования к реализации: При выполнении задания вы можете создавать любые методы/конструкторы или 
даже структуры/классы, если они вам нужны. Реализовывать методы, которые уже объявленны в шаблоне, 
не нужно  они уже реализованы. При выполнении задания не вводите и не выводите что-либо. 
Реализовывать функцию main не нужно.
*/

#include <cstddef> // size_t
#include <string.h>

struct String {
	String(const char *str = "");
	String(const String &other);
	String(size_t n, char c);
	~String();

	void append(const String &other);
	String operator[] (size_t) const;

	size_t size;
	char *str;
	size_t old_size = 0;
};

String::String(const String &other) {
	this->size = other.size;
	this->old_size = other.old_size;
	this->str = new char[size + 1];
	strncpy(this->str, other.str, this->size);
	this->str[this->size] = 0;
}
String String::operator[] (size_t index) const {
	if (old_size == 0) {
		size_t new_size = this->size - index;
		char *new_str = new char[new_size + 1];
		strncpy(new_str, this->str + index, new_size);
		new_str[new_size] = 0;
		String new_string(new_str);
		delete[] new_str;
		new_string.old_size = this->size;
		return new_string;
	}
	size_t new_size = this->size - (this->old_size - index);
	char *new_str = new char[new_size + 1];
	strncpy(new_str, str, new_size);
	new_str[new_size] = 0;
	String new_string(new_str);
	delete[] new_str;
	new_string.old_size = 0;
	return new_string;
}
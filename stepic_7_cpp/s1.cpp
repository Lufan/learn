/*
Реализуйте функцию getline, которая считывает поток ввода посимвольно, пока не достигнет конца потока или не 
встретит символ переноса строки ('\n'), и возвращает C-style строку с прочитанными символами.

Обратите внимание, что так как размер ввода заранее неизвестен, то вам нужно будет перевыделять память в 
процессе чтения, если в потоке ввода оказалось больше символов, чем вы ожидали.

Память, возвращенная из функции будет освобождена оператором delete[]. Символ переноса строки ('\n') 
добавлять в строку не нужно, но не забудьте, что в конце C-style строки должен быть завершающий нулевой символ.

Требования к реализации: при выполнении данного задания вы можете определять любые вспомогательные функции, 
если они вам нужны. Определять функцию main не нужно.
*/

#include <iostream>

char *resize(const char *str, unsigned size, unsigned new_size)
{
	if (new_size == 0) return 0;
	if (new_size == size) return (char*)str;
	char *new_str = new char[new_size];
	unsigned size_to_copy = (new_size > size) ? size : new_size;
	for (unsigned i = 0; i < size_to_copy; i++) {
		new_str[i] = str[i];
	}
	delete[] str;
	return new_str;
}

char *getline()
{
	char *str = new char[100];
	char ch = 0;
	unsigned size = 100;
	unsigned pos = 0;
	while (true) {
		std::cin.get(ch);

		if (ch == '\n') break;
		if (std::cin.eof()) break;

		str[pos] = ch;
		pos++;
		if (pos == size) {
			str = resize(str, size, size * 2);
			size = size * 2;
		}
	}
	str[pos] = 0;
	return str;
}
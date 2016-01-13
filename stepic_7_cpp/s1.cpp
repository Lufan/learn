/*
���������� ������� getline, ������� ��������� ����� ����� �����������, ���� �� ��������� ����� ������ ��� �� 
�������� ������ �������� ������ ('\n'), � ���������� C-style ������ � ������������ ���������.

�������� ��������, ��� ��� ��� ������ ����� ������� ����������, �� ��� ����� ����� ������������ ������ � 
�������� ������, ���� � ������ ����� ��������� ������ ��������, ��� �� �������.

������, ������������ �� ������� ����� ����������� ���������� delete[]. ������ �������� ������ ('\n') 
��������� � ������ �� �����, �� �� ��������, ��� � ����� C-style ������ ������ ���� ����������� ������� ������.

���������� � ����������: ��� ���������� ������� ������� �� ������ ���������� ����� ��������������� �������, 
���� ��� ��� �����. ���������� ������� main �� �����.
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
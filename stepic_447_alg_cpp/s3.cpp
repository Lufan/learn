/*
Задача на программирование

Дана строка s длины не более 10^5, состоящая только из символов 0 и 1. Со строкой разрешается делать 
следующую операцию: взять префикс строки и поменять в нём всё нули на единицы, а все единицы — на нули 
(другими словами, инвертировать все символы префикса). Выведите минимальное количество операций, 
требующееся, чтобы из строки s получить строку, состоящую из всех нулей.

Sample Input:
010
Sample Output:
2
*/

#include <iostream>
#include <string>


unsigned int change_count(std::string &str) {
	unsigned int count = 0;
	bool is1 = false;
	size_t size = str.size();
	for (int i = size - 1; i >= 0; --i) {
		if (str[i] == '1' && !is1) {
			is1 = true;
			++count;
		}
		else if (str[i] == '0' && is1) {
			is1 = false;
			++count;
		}
	}
	return count;
}

int main()
{
	std::string str;
	std::cin >> str;
	std::cout << change_count(str) << std::endl;
	return 0;
}
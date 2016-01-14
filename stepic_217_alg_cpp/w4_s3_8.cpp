/*
Задача на программирование: расстояние редактирования

Вычислите расстояние редактирования двух данных непустых строк длины не более 10^2, 
содержащих строчные буквы латинского алфавита.

Sample Input 1:
ab
ab
Sample Output 1:
0

Sample Input 2:
short
ports
Sample Output 2:
3
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


int main()
{
	// Считываем первую строку
	std::string strA;
	std::cin >> strA;
	// Считываем вторую строку
	std::string strB;
	std::cin >> strB;
	// Определяем размер строк
	auto sizeA = strA.size();
	auto sizeB = strB.size();
	// Создаем массивы для двух строк
	std::vector<std::vector<int>> tab;
	// Инициализируем данные
	for (auto i = 0; i <= sizeB; ++i) tab.push_back(std::vector<int>(sizeA + 1));
	for (auto i = 0; i <= sizeA; ++i) tab[0][i] = i;
	for (auto i = 1; i <= sizeB; ++i) tab[i][0] = i;
	// Считаем таблицу
	for (auto j = 1; j <= sizeB; ++j) {
		for (auto i = 1; i <= sizeA; ++i) {
			auto c = (strA.at(i - 1) == strB.at(j - 1)) ? 0 : 1;
			auto min_val = std::min({ tab[j][i - 1] + 1, tab[j - 1][i] + 1, tab[j - 1][i - 1] + c });
			tab[j][i] = min_val;
		}
	}
	std::cout << tab[sizeB][sizeA] << std::endl;
	return 0;
}

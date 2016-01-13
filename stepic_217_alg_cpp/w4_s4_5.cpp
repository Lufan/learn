/*
Задача на программирование: рюкзак

Первая строка входа содержит целые числа 1≤W≤10^4 и 1≤n≤300 — вместимость рюкзака и 
число золотых слитков. Следующая строка содержит n целых чисел 0≤w1,…,wn≤10^5, задающих 
веса слитков. Найдите максимальный вес золота, который можно унести в рюкзаке.

Sample Input:
10 3
1 4 8
Sample Output:
9
*/

#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
	//Считываем вместимость рюкзака
	size_t W = 0;
	std::cin >> W;
	// Считываем количество вещей
	size_t n = 0;
	std::cin >> n;
	// Считываем веса вещей
	std::vector<int> v;
	for (auto i = 0; i < n; ++i) {
		auto value = 0;
		std::cin >> value;
		v.push_back(value);
	}
	// Инициализируем таблицу значений
	std::vector<std::vector<int>> tab(W + 1, std::vector<int>(n + 1, 0));
	// Рассчитываем значения
	for (size_t j = 1; j <= n; ++j) {
		for (size_t w = 1; w <= W; ++w) {
			if (v[j - 1] > w) tab[w][j] = tab[w][j - 1];
			else tab[w][j] = std::max({ tab[w][j - 1], tab[w - v[j - 1]][j - 1] + v[j - 1] });
		}
	}
	std::cout << tab[W][n] << std::endl;
	return 0;
}
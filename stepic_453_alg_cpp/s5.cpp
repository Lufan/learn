/*
Задача на программирование.

Дано натуральное число n≤10^5 , не отрицательное x и массив не отрицательных чисел a1,…,an . x и ai не превосходят 10^9. 
Вам требуется вывести размер максимального подмножества I⊆{1,…,n} т.ч. для любых двух неравных i,j∈I выполняется, что ai+aj>x.

Sample Input:
10 48
57 26 9 94 72 70 45 4 86 83
Sample Output:
8
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	size_t N = 0;
	std::cin >> N;
	size_t X = 0;
	std::cin >> X;
	std::vector<int> v;
	for (auto i = 0; i < N; ++i) {
		auto value = 0;
		std::cin >> value;
		v.push_back(value);
	}

	// Инициализируем таблицу значений
	std::vector<std::vector<int>> tab(N + 1, std::vector<int>(N + 1, 0));
	// Рассчитываем значения
	for (size_t j = 0; j < N; ++j) {
		int count = 0;
		for (size_t w = 0; w < N; ++w) {
			if (w != j && v[j] + v[w] > X) {
				tab[j][w] = 1;
				++count;
			}
		}
		tab[j][N] = count;
	}
	int max = 0;
	for (int i = 0; i < N; ++i) max += tab[N - i][i];

	std::cout << max << std::endl;

	return 0;
}

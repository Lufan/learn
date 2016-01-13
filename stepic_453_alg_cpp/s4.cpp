/*
Число разбиений на слагаемые

По данному целому числу 1≤n≤1000 найдите число способов представить n в виде суммы положительных целых чисел. 
Выведите данное число по модулю 10^9+7. Два представления, отличающиеся друг от друга только порядком слагаемых, 
считаем одинаковыми.

Sample Input:
5
Sample Output:
7
*/

#include <iostream>
#include <vector>
#include <cstdint>
#include <cmath>

int main()
{
	int n = 0;
	std::cin >> n;

	std::vector<std::vector<uintmax_t>> tabl;
	for (int i = 0; i <= n; ++i) tabl.push_back(std::move(std::vector<uintmax_t>(n + 1)));

	uintmax_t modul = (uintmax_t)std::pow(10, 9) + 7;
	tabl[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			for (int k = 0; k <= j; ++k) {
				if (tabl[i][j] > modul) { tabl[i][j] = tabl[i][j] % modul; }
				if (tabl[i - j][k] > modul) { tabl[i - j][k] = tabl[i - j][k] % modul; }
				tabl[i][j] = tabl[i][j] + tabl[i - j][k];
			}
		}
	}
	tabl[0][0] = 0;

	uintmax_t res = tabl[n][1];

	for (int i = 2; i <= n; ++i)
	{
		res += tabl[n][i];
		if (res > modul) { res = res % modul; }
	}
	std::cout << res % modul << std::endl;
	//std::cout << (res % ((uintmax_t)std::pow(10, 9) + 7)) << std::endl;
	return 0;
}

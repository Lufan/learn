/*
Задача на программирование

По данным числам 1≤n≤30 и 1≤w≤10^9 и набору чисел 1≤v1,…,vn≤10^9 найдите минимальное число k, для которого число w 
можно представить как сумму k чисел из набора {v1,…,vn}. Каждое число из набора можно использовать сколько угодно 
раз. Известно, что в наборе есть единица и что для любой пары чисел из набора одно из них делится на другое. 
Гарантируется, что в оптимальном ответе число слагаемых не превосходит 10^4.

Выведите число k и сами слагаемые.

Sample Input:
4 90 1 2 10 50
Sample Output:
5 50 10 10 10 10
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	// Считываем число элементов
	int N = 0;
	std::cin >> N;
	// Считываем значение суммы
	int W = 0;
	std::cin >> W;
	// Считываем значения элементов
	std::vector<int> v;
	int n = N;
	while (n > 0) {
		int value = 0;
		std::cin >> value;
		v.push_back(value);
		--n;
	}
	std::sort(v.begin(), v.end());
	std::vector<int> res;
	// Рассчитываем значения
	for (int i = N - 1; i >= 0; --i) {
		while (true) {
			if (W - v[i] >= 0) {
				res.push_back(v[i]);
				W -= v[i];
			}
			else break;
		}
		if (W == 0) break;
	}
	std::cout << res.size();
	for (auto elem : res) std::cout << " " << elem;
	std::cout << std::endl;
	return 0;
}

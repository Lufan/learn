/*
Задача на программирование повышенной сложности

На доске написано n чисел. С ними n−1 раз повторяется следующая простая операция: стираются текущий минимум и 
текущий максимум, выписывается их полусумма. Ваша задача — определить, какое число останется в конце.

Во входе дано целое число 1≤n≤10^5 и начальные целые числа  −10^5≤a1,…,an≤10^5. Выведите итоговое число с точностью 10−6.

Sample Input:
3 2 3 9
Sample Output:
4.2500000
*/

#include <iostream>
#include <list>
#include <algorithm>
#include <iomanip>
/*
На доске написано n чисел. С ними n−1 раз повторяется следующая простая операция: стираются текущий минимум и
текущий максимум, выписывается их полусумма. Ваша задача — определить, какое число останется в конце.

Во входе дано целое число 1≤n≤10^5 и начальные целые числа  −10^5≤a1,…,an≤10^5. Выведите итоговое число с точностью 10e−6.

Sample Input:
3 2 3 9
Sample Output:
4.2500000
*/
int main()
{
	int N = 0;
	std::cin >> N;
	std::list<double> v;
	int n = N;
	while (n > 0) {
		int value = 0;
		std::cin >> value;
		v.push_back(value);
		--n;
	}
	v.sort();
	while (N > 1) {
		double num1 = *(v.begin());
		double num2 = *(--v.end());
		v.pop_back();
		v.pop_front();
		double new_num = (num1 + num2) / 2.0;
		auto pos = std::upper_bound(v.begin(), v.end(), new_num);
		v.insert(pos, new_num);
		--N;
	}

	std::cout << std::setprecision(8) << std::showpoint << *v.begin() << std::endl;
	return 0;
}

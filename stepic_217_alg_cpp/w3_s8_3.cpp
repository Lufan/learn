/*
https://stepic.org/lesson/%D0%A1%D0%BE%D1%80%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%BA%D0%B8-%D0%BE%D1%81%D0%BD%D0%BE%D0%B2%D0%B0%D0%BD%D0%BD%D1%8B%D0%B5-%D0%BD%D0%B5-%D0%BD%D0%B0-%D1%81%D1%80%D0%B0%D0%B2%D0%BD%D0%B5%D0%BD%D0%B8%D1%8F%D1%85-13252/step/3?unit=3437
Задача на программирование: сортировка подсчётом

Первая строка содержит число 1≤n≤104, вторая — n натуральных чисел, не превышающих 10. 
Выведите упорядоченную по неубыванию последовательность этих чисел.

Sample Input:
5
2 3 9 2 9
Sample Output:
2 2 3 9 9
*/

#include <iostream>
#include <sstream>
#include <vector>


int main()
{
	int n = 0;
	std::cin >> n;
	std::vector<unsigned int> b(11);
	while (--n >= 0) {
		unsigned int value = 0;
		std::cin >> value;
		b[value] += 1;
	}
	std::ostringstream oss;
	for (unsigned int i = 0; i < 11; ++i)
		for (unsigned int j = 0; j < b[i]; ++j) oss << i << " ";
	std::cout << oss.str() << std::endl;
	return 0;
}
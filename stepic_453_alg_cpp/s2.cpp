/*
Представитель большинства
﻿
Дано натуральное число 1≤n≤105 и последовательность целых чисел −10^9≤a1,…,an≤10^9. Выведите 1, 
если в последовательности есть число, встречающееся строго больше n/2 раз, и 0 в противном случае.
Sample Input:
5
2 3 9 2 2
Sample Output:
1
*/

#include <iostream>
#include <map>

int main()
{
	int elem_count = 0;
	std::cin >> elem_count;
	int n = elem_count / 2;
	std::map<int, int> elements;
	while (elem_count > 0) {
		int value = 0;
		std::cin >> value;
		auto pos = elements.find(value);
		if (pos != elements.end()) {
			int cur_count = (*pos).second;
			(*pos).second = cur_count + 1;
			if (cur_count >= n) {
				std::cout << "1" << std::endl;
				return 0;
			}
		}
		else {
			elements.insert(std::make_pair(value, 1));
		}
		--elem_count;
	}
	std::cout << "0" << std::endl;
	return 0;
}
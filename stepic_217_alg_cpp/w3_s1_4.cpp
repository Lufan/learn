/*
https://stepic.org/lesson/%D0%94%D0%B2%D0%BE%D0%B8%D1%87%D0%BD%D1%8B%D0%B9-%D0%BF%D0%BE%D0%B8%D1%81%D0%BA-13246/step/4?unit=3431
Задача на программирование: двоичный поиск

В первой строке даны целое число 1≤n≤10^5 и массив A[1…n] из n различных натуральных чисел, не превышающих 10^9, 
в порядке возрастания, во второй — целое число 1≤k≤10^5 и k натуральных чисел b1,…,bk, не превышающих 10^9. 
Для каждого i от 1 до k необходимо вывести индекс 1≤j≤n, для которого A[j]=bi, или −1, если такого j нет.

Sample Input:
5 1 5 8 12 13
5 8 1 23 1 11
Sample Output:
3 1 -1 1 -1
*/

#include <iostream>
#include <vector>

int my_bsearch(int val, std::vector<int>& mas) {
	int l = 0;
	int r = mas.size() - 1;
	if (val > mas.at(r)) return -1;
	while (l <= r) {
		int m = l + (r - l) / 2;
		unsigned int elem = mas.at(m);
		if (elem == val) return m + 1; // Для нумерации с 1
		if (val > elem) l = m + 1;
		else r = m - 1;
	}
	return -1;
}

int main()
{
	int num_count = 0;
	std::cin >> num_count;
	std::vector<int> mas;
	while (num_count-- > 0) {
		int val = 0;
		std::cin >> val;
		mas.push_back(val);
	}
	std::cin >> num_count;
	std::vector<int> nums_to_seach;
	while (num_count-- > 0) {
		int val = 0;
		std::cin >> val;
		nums_to_seach.push_back(val);
	}
	for (auto val : nums_to_seach) {
		std::cout << my_bsearch(val, mas) << " ";
	}
	std::cout << std::endl;
	std::cout.flush();
	return 0;
}


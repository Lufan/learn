/*
Задача на программирование: наибольшая последовательнократная подпоследовательность

Дано целое число 1≤n≤10^3 и массив A[1…n] натуральных чисел, не превосходящих 2⋅10^9. Выведите максимальное 1≤k≤n, 
для которого найдётся подпоследовательность 1≤i1<i2<…<ik≤n длины k, в которой каждый элемент делится на предыдущий 
(формально: для  всех 1≤j<k, A[ij]|A[ij+1]).

Sample Input:
4
3 6 7 12
Sample Output:
3
*/

#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
	int num = 0;
	std::cin >> num;
	std::vector<int> arr;
	while (--num >= 0) {
		int val = 0;
		std::cin >> val;
		arr.push_back(val);
	}
	auto size = arr.size();
	std::vector<int> path_len(size);
	for (int i = 0; i < size; ++i) {
		path_len[i] = 1;
		for (int j = 0; j < i; ++j) {
			if ((arr[i] % arr[j] == 0) && (path_len[j] + 1 > path_len[i])) {
				path_len[i] = path_len[j] + 1;
			}
		}
	}
	auto res = std::max_element(path_len.begin(), path_len.end(), [](int e1, int e2) {return e1 < e2;});
	std::cout << *res << std::endl;

	return 0;
}
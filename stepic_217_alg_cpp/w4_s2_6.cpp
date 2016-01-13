/*
https://stepic.org/lesson/%D0%9D%D0%B0%D0%B8%D0%B1%D0%BE%D0%BB%D1%8C%D1%88%D0%B0%D1%8F-%D0%B2%D0%BE%D0%B7%D1%80%D0%B0%D1%81%D1%82%D0%B0%D1%8E%D1%89%D0%B0%D1%8F-%D0%BF%D0%BE%D0%B4%D0%BF%D0%BE%D1%81%D0%BB%D0%B5%D0%B4%D0%BE%D0%B2%D0%B0%D1%82%D0%B5%D0%BB%D1%8C%D0%BD%D0%BE%D1%81%D1%82%D1%8C-13257/step/6?unit=3442
Задача на программирование повышенной сложности: наибольшая невозрастающая подпоследовательность

Дано целое число 1≤n≤10^5 и массив A[1…n], содержащий неотрицательные целые числа, не превосходящие 10^9. 
Найдите наибольшую невозрастающую подпоследовательность в A. В первой строке выведите её длину k, во второй — 
её индексы 1≤i1<i2<…<ik≤n (таким образом, A[i1]≥A[i2]≥…≥A[in]).

Sample Input:
5
5 3 4 4 2
Sample Output:
4
1 3 4 5
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

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
	std::vector<int> path_len(size + 1);
	std::vector<int> pos(size + 1);
	for (size_t i = 0; i < size + 1; ++i) pos[i] = -1;
	path_len[0] = std::numeric_limits<int>::max();
	for (size_t i = 1; i < size + 1; ++i) path_len[i] = std::numeric_limits<int>::min();

	for (size_t i = 0; i < size; ++i) {
		size_t j = static_cast<size_t>(std::upper_bound(path_len.begin(), path_len.end(), arr[i],
			[](int e1, int e2) { return e1 > e2;}) - path_len.begin());
		if ((path_len[j] < arr[i]) && (path_len[j - 1] >= arr[i])) {
			path_len[j] = arr[i];
			pos[j] = i;
		}
		else if (j == 0) {
			path_len[1] = arr[0];
			pos[1] = 0;
		}
		/*
		for (int j = size - 1; j > i; --j) {
		if ((arr[i] >= arr[j]) && (path_len[j] + 1 > path_len[i])) {
		path_len[i] = path_len[j] + 1;
		}
		}
		*/
	}
	auto res = std::count_if(path_len.begin(), path_len.end(), [](int e1) {return e1 > std::numeric_limits<int>::min() && e1 < std::numeric_limits<int>::max();});
	std::cout << res << std::endl;
	std::ostringstream oss;
	for (int i = 0; i < size + 1; ++i) {
		if (pos[i] >= 0) {
			oss << pos[i] + 1 << " ";
		}
	}
	std::cout << oss.str() << std::endl;

	return 0;
}

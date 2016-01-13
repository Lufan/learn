/*

Задача на программирование: число инверсий

Первая строка содержит число 1≤n≤105, вторая — массив A[1…n], содержащий натуральные числа, 
не превосходящие 10^9. Необходимо посчитать число пар индексов 1≤i<j≤n, для которых A[i]>A[j]. 
(Такая пара элементов называется инверсией массива. Количество инверсий в массиве является в некотором 
смысле его мерой неупорядоченности: например, в упорядоченном по неубыванию массиве инверсий нет вообще, 
а в массиве, упорядоченном по убыванию, инверсию образуют каждые два элемента.)

Sample Input:
5
2 3 9 2 9
Sample Output:
2
*/

#include <iostream>
#include <vector>

std::vector<unsigned int> merge(std::vector<unsigned int> a1, std::vector<unsigned int> a2, long& count) {
	std::vector<unsigned int> result;
	auto p1 = a1.begin();
	auto p2 = a2.begin();
	bool isP2 = false, isP1 = false;
	while (true) {
		if (*p1 <= *p2) {
			//std::cout << "p1 = " << *p1 << " p2 = " << *p2 << std::endl;
			result.push_back(*p1);
			p1++;
			if (p1 == a1.end()) {
				isP1 = true;
				break;
			}
		}
		else {
			size_t c = (a1.end() - p1);// +(p2 - a2.begin());
									   //std::cout << "p1 = " << *p1 << " p2 = " << *p2 << " + " << c << std::endl;
			count += c;
			result.push_back(*p2);
			p2++;
			if (p2 == a2.end()) {
				isP2 = true;
				break;
			}
		}
	}
	if (isP1) result.insert(result.end(), p2, a2.end());
	else result.insert(result.end(), p1, a1.end());
	return result;
}

std::vector<unsigned int> merge_sort(std::vector<unsigned int>& a, size_t l, size_t r, long& count) {
	if (r == l) {
		std::vector<unsigned int> vec;
		vec.push_back(a[r]);
		return vec; // Если границы пересеклись
	}
	size_t m = l + (r - l) / 2; // Делим пополам
	return merge(merge_sort(a, l, m, count), merge_sort(a, m + 1, r, count), count);

}

int main()
{
	unsigned int size = 0;
	std::vector<unsigned int> mas;
	std::cin >> size;
	while (size-- >= 1) {
		unsigned int val = 0;
		std::cin >> val;
		mas.push_back(val);
	}
	long count = 0;
	auto a = merge_sort(mas, 0, mas.size() - 1, count);
	std::cout << count << std::endl;
	//for (auto elem : a) std::cout << elem << " ";
	//std::cout << std::endl;
	return 0;
}
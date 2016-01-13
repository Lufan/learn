/*
Максимальное попарное произведение

В первой строке входа дано целое число 2≤n≤2⋅10^5, во второй — последовательность целых чисел0≤a1,a2,…,an≤10^5. 
Выведите максимальное попарное произведение двух элементов последовательности, то есть max(aiaj) 1≤i≠j≤n.

Sample Input:
3
1 2 3
Sample Output:
6
*/

#include <iostream>
#include <set>


struct comparator {
	bool operator() (const int &e1, const int &e2) const { return e1 > e2; }
};

int main()
{
	int elem_count = 0;
	std::cin >> elem_count;
	std::multiset<int, comparator> elements;

	while (elem_count > 0) {
		int value = 0;
		std::cin >> value;
		elements.insert(value);
		--elem_count;
	}
	long long first = *elements.begin();
	long long second = *(++elements.begin());
	long long result = first * second;
	std::cout << result << std::endl;
	return 0;
}

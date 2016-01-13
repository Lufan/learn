/*
Даны два массива целых чисел одинаковой длины A[0..n−1] и B[0..n−1].
Необходимо найти первую пару индексов i0 и j0, i0≤j0, такую что A[i0]+B[j0]=max{A[i]+B[j],где0≤i<n,0≤j<n,i≤j}.
Время работы – O(n).
Ограничения: 1≤n≤100000,0≤A[i]≤100000,0≤B[i]≤100000  для любого i.
Sample Input:
4
4 -8 6 0
-10 3 1 1
Sample Output:
0 1
*/

#include <iostream>
#include <vector>
#include <limits>


int main()
{
	int n = 0;
	std::cin >> n;
	std::vector<int> v1, v2;
	for (int i = 0; i < n; ++i) {
		int value = 0;
		std::cin >> value;
		v1.push_back(value);
	}
	for (int i = 0; i < n; ++i) {
		int value = 0;
		std::cin >> value;
		v2.push_back(value);
	}
	// Создаем массив с максимумами по 1 массиву для каждого элемента 
	// второго массива
	int max = std::numeric_limits<int>::min();
	std::vector<int> max_pos_1(n);
	int curr_max = 0;
	for (int i = 0; i < n; ++i) {
		if (v1[i] > max) {
			max = v1[i];
			curr_max = i;
		}
		max_pos_1[i] = curr_max;
	}

	// Проходим по 2 массиву находя наибольшую сумму
	int first_pos = 0, second_pos = 0;
	max = std::numeric_limits<int>::min();
	for (int i = 0; i < n; ++i) {
		curr_max = v2[i] + v1[max_pos_1[i]];
		if (curr_max > max) {
			max = curr_max;
			first_pos = max_pos_1[i];
			second_pos = i;
		}
	}

	std::cout << first_pos << " " << second_pos << std::endl;
	return 0;
}
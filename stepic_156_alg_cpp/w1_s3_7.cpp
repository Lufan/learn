/*
Дан отсортированный массив различных целых чисел A[0..n-1] и массив целых чисел B[0..m-1].
Для каждого элемента массива B[i] найдите минимальный индекс элемента массива A[k],
ближайшего по значению к B[i].
Время работы поиска для каждого элемента B[i]: O(log(k)).
Подсказка. Обратите внимание, что время работы должно зависеть от индекса ответа - k. 
Для достижения такой асимптотики предлагается для начала найти отрезок вида [2p,2p+1] , 
содержащий искомую точку, а уже затем на нём выполнять традиционный бин. поиск.
Sample Input:
3
10 20 30
3
9 15 35
Sample Output:
0 0 2
*/

#include <iostream>
#include <vector>
#include <cmath>

int main()
{
	// Первый массив
	int n = 0;
	std::cin >> n;
	std::vector<int> v1;
	for (int i = 0; i < n; ++i) {
		int value = 0;
		std::cin >> value;
		v1.push_back(value);
	}
	// Второй массив
	int m = 0;
	std::cin >> m;
	std::vector<int> v2;
	for (int i = 0; i < m; ++i) {
		int value = 0;
		std::cin >> value;
		v2.push_back(value);
	}

	for (auto elem : v2) {
		// Поиск окресности элемента в 1 массиве
		int start_pos = 0, end_pos = 2;
		while (end_pos < n) {
			if (v1[end_pos] > elem) break;
			start_pos = end_pos;
			end_pos *= 2;
		}
		// Выполняем поиск ближайшего элемента по установленному
		// интервалу
		end_pos = (end_pos >= n) ? n : end_pos;
		while (start_pos < end_pos) {
			int mid_pos = start_pos + (end_pos - start_pos) / 2;
			if (v1[mid_pos] > elem) {
				end_pos = mid_pos;
			}
			else if (v1[mid_pos] < elem) {
				start_pos = mid_pos + 1;
			}
			else {
				start_pos = mid_pos;
				end_pos = mid_pos;
				break;
			}
		}
		if (start_pos != 0 && start_pos != n) {
			start_pos = start_pos - 1;
			start_pos = (abs(v1[start_pos] - elem) > abs(v1[end_pos] - elem)) ? end_pos : start_pos;
		}
		else if (start_pos == n) start_pos = n - 1;

		std::cout << start_pos << " ";
	}
	std::cout << std::endl;
	return 0;
}
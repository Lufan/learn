/*
Реализуйте сортировку вставками массива целых чисел.
Количество чисел в массиве определяется окончанием стандартного 
потока ввода и заранее не известно.

Sample Input:
3 1 2
Sample Output:
1 2 3
*/

#include <iostream>
#include <vector>


int main()
{
	int value = 0;
	std::vector<int> arr;
	while (std::cin >> value) arr.push_back(value);

	int size = arr.size();
	for (int i = 1; i < size; ++i) {
		int temp = arr[i];
		int j = i - 1;
		for (; j >= 0 && temp < arr[j]; --j) {
			arr[j + 1] = arr[j];
			arr[j] = temp;
		}
	}

	for (auto elem : arr) std::cout << elem << " ";
	std::cout << std::endl;
	return 0;
}



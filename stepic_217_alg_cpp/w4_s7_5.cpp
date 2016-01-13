/*
Задача на программирование: калькулятор

У вас есть примитивный калькулятор, который умеет выполнять всего три операции с текущим числом x: заменить x на 2x, 
3x или x+1. По данному целому числу 1≤n≤105 определите минимальное число операций k, необходимое, чтобы получить n из 1. 
Выведите k и последовательность промежуточных чисел.

Sample Input 1:
1
Sample Output 1:
0
1

Sample Input 2:
5
Sample Output 2:
3
1 2 4 5

Sample Input 3:
96234
Sample Output 3:
14
1 3 9 10 11 22 66 198 594 1782 5346 16038 16039 32078 96234
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

int main()
{
	// Считываем число N
	size_t N = 0;
	std::cin >> N;
	/*
	Будем искать минимальное количество операций для каждого числа. Обозначим S[i] - минимальное число операций
	для числа i. Выразим S[i] через ответы для меньших подзадач. S[i] = min{S[i/3] + 1, S[i/2] + 1, S[i-1] + 1}, причем
	деление выполняется в случае делимости i нацело.
	*/
	// Промежуточные результаты складываем в массив
	std::vector<size_t> S;
	// Массив для отслеживания промежуточных чисел
	std::vector<std::vector<size_t>> path(N + 1, std::vector<size_t>());
	S.push_back(0);
	S.push_back(0);       // Для i = 1 требуется 0 операций
	path[1].push_back(1); // Для i = 1 промежуточное значение и есть 1
	for (size_t i = 2; i <= N; ++i) {
		size_t x_div_3 = std::numeric_limits<int>::max();
		if ((i % 3) == 0) x_div_3 = S[i / 3] + 1;
		size_t x_div_2 = std::numeric_limits<int>::max();
		if ((i % 2) == 0) x_div_2 = S[i / 2] + 1;
		size_t min_val = std::min({ x_div_3, x_div_2, S[i - 1] + 1 });
		S.push_back(min_val);
		if (min_val == x_div_3) { path[i] = path[i / 3]; path[i].push_back(i); }
		if (min_val == x_div_2) { path[i] = path[i / 2]; path[i].push_back(i); }
		if (min_val == S[i - 1] + 1) { path[i] = path[i - 1]; path[i].push_back(i); }
	}
	std::cout << S[N] << std::endl;
	// Восстанавливаем решение
	for (auto elem : path[N]) std::cout << elem << " ";
	std::cout << std::endl;
	return 0;
}

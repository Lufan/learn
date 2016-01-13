/*
Задача на программирование: лестница

Даны число 1≤n≤10^2 ступенек лестницы и целые числа −10^4≤a1,…,an≤10^4, которыми помечены ступеньки. 
Найдите максимальную сумму, которую можно получить, идя по лестнице снизу вверх (от нулевой до n-й ступеньки), 
каждый раз поднимаясь на одну или две ступеньки.

Sample Input 1:
2
1 2
Sample Output 1:
3

Sample Input 2:
2
2 -1
Sample Output 2:
1

Sample Input 3:
3
-1 2 1
Sample Output 3:
3
*/

#include <iostream>
#include <vector>
#include <algorithm>

/*
Дана число 1≤n≤10^2 ступенек лестницы и целые числа −10^4≤a1,…,an≤10^4,
которыми помечены ступеньки. Найдите максимальную сумму, которую можно получить,
идя по лестнице снизу вверх (от нулевой до n-й ступеньки), каждый раз поднимаясь
на одну или две ступеньки.

Sample Input 1:
2
1 2
Sample Output 1:
3

Sample Input 2:
2
2 -1
Sample Output 2:
1

Sample Input 3:
3
-1 2 1
Sample Output 3:
3
*/


int main()
{
	// Считываем число ступеней
	size_t count = 0;
	std::cin >> count;
	// Считываем значения ступеней
	std::vector<int> nominals;
	nominals.push_back(0);
	for (size_t i = 0; i < count; ++i) {
		int value = 0;
		std::cin >> value;
		nominals.push_back(value);
	}
	/*
	Будем искать максимальную сумму для каждой ступени. Обозначим через S[i] максимальную сумму для ступеней от 0 до i.
	Выразим S[i] через ответы для меньших подзадач. Тогда S[i] = min{S[i-1] + S[i], S[i-2] + S[i]}. Первые два элемента
	равны 0 и nominals[1].
	*/
	// Инициализируем массив
	std::vector<int> S;
	S.push_back(0);           // 0-я ступень
	S.push_back(nominals[1]); // 1-я ступень
	for (size_t i = 2; i <= count; ++i) S.push_back(std::max({ S[i - 1] + nominals[i], S[i - 2] + nominals[i] }));
	// Выводим значение в последней ступени
	std::cout << S[count] << std::endl;
	return 0;
}

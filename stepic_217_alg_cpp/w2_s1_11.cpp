/*
https://stepic.org/lesson/%D0%92%D0%B2%D0%B5%D0%B4%D0%B5%D0%BD%D0%B8%D0%B5-13238/step/11?unit=3424
Задача на программирование: различные слагаемые

По данному числу 1≤n≤109 найдите максимальное число k, для которого n можно представить как 
сумму k различных натуральных слагаемых. Выведите в первой строке число k, во второй — k слагаемых.

Sample Input 1:
4
Sample Output 1:
2
1 3

Sample Input 2:
6
Sample Output 2:
3
1 2 3
*/

#include <iostream>
#include <cmath>


int main()
{
	unsigned int number = 0;
	// Считываем число
	std::cin >> number;
	// Находим число k, такое что сумма чисел от 1 до k меньше либо равна нашему числу number
	double kd = (-1.0 + std::sqrt(1.0 + 8.0 * ((double)number))) / 2.0;
	unsigned int k = (unsigned int)kd; // Отбрасываем дробную часть
									   // Выводим количество слагаемых
	std::cout << k << std::endl;
	// Выводим натуральные числа от 1 до k-1 и результат выражения от number - sum(k-1)
	for (unsigned int i = 1; i <= k - 1; ++i) std::cout << i << " ";
	std::cout << (number - (k - 1) * k / 2) << std::endl;

	return 0;
}
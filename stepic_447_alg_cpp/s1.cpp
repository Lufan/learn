/*
Задача на программирование

По данным двум числам 1≤a,b≤2⋅10^9 найдите наименьшее натуральное число m, которое делится и на a, и на b.

Sample Input:
18 35
Sample Output:
630
*/

#include <iostream>

unsigned int NOD(unsigned int a, unsigned int b) {
	if (b == 0) return a;
	else return NOD(b, a % b);
}

int main()
{
	unsigned int num1 = 0;
	unsigned int num2 = 0;
	// Считываем два числа
	std::cin >> num1 >> num2;
	// Находим NOD
	unsigned int nod = 0;
	if (num1 >= num2) nod = NOD(num1, num2);
	else nod = NOD(num2, num1);
	//std::cout << nod << std::endl;
	// Находим наименьшее число делящееся на оба заданных числа
	unsigned long long result = (unsigned long long)num1 * (unsigned long long)num2 / (unsigned long long)nod;
	std::cout << result << std::endl;
	return 0;
}
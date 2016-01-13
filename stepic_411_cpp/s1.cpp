/*
Напишите программу, которая по целому положительному числу N вычисляет количество положительных целых чисел 
меньших N таких, что их сумма цифр (в десятичной записи) равна сумме цифр в числе N.

Формат входа: целое положительное число N<107.

Формат вывода: количество таких целых положительных чисел меньших N, у которых сумма цифр равняется сумме цифр числа N.

Sample Input:
123
Sample Output:
9
*/

#include <iostream>

int sumNum(long int N) {
	int c = N / 10;
	int sum = 0 + (N - c * 10);
	while (c != 0) {
		sum = sum + (c - (c / 10) * 10);
		c = c / 10;
	}
	return sum;
}

int main() {
	long int N = 0;
	std::cin >> N;
	int sum = sumNum(N);
	int num = 0;
	for (long int i = N - 1; i > 0; i--) {
		if (sum == sumNum(i)) num++;
	}
	std::cout << num;
	return 0;
}
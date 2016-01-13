/*
https://stepic.org/lesson/%D0%A7%D0%B8%D1%81%D0%BB%D0%B0-%D0%A4%D0%B8%D0%B1%D0%BE%D0%BD%D0%B0%D1%87%D1%87%D0%B8-13228/step/6?unit=3414
Задача на программирование: небольшое число Фибоначчи

Дано целое число 1≤n≤40, необходимо вычислить n-е число Фибоначчи (напомним, что F0=0, F1=1 и Fn=Fn−1+Fn−2 при n≥2).

Sample Input:
3
Sample Output:
2
*/
#include <iostream>
#include <vector>

int main()
{
	int n = 0;
	std::cin >> n;
	std::vector<int> fib(n + 1);
	fib[0] = 0;
	fib[1] = 1;
	for (int j = 2; j <= n; ++j) fib[j] = fib[j - 1] + fib[j - 2];

	std::cout << fib[n] << std::endl;
	return 0;
}
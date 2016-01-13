/*
https://stepic.org/lesson/%D0%A7%D0%B8%D1%81%D0%BB%D0%B0-%D0%A4%D0%B8%D0%B1%D0%BE%D0%BD%D0%B0%D1%87%D1%87%D0%B8-13228/step/8?unit=3414
Задача на программирование повышенной сложности: огромное число Фибоначчи по модулю

Даны целые числа 1≤n≤10^18 и 2≤m≤10^5, необходимо найти 
остаток от деления n-го числа Фибоначчи на m.

Sample Input:
16759108071127739 44408
Sample Output:
22937
*/
#include <iostream>
#include <vector>


int main()
{
	long long n = 0;
	long long m = 0;
	std::cin >> n >> m;
	std::vector<long long> fib(2);
	fib[0] = 0;
	fib[1] = 1;
	long long t = 0;
	for (long long j = 2; j < n; ++j) {
		fib.push_back((fib[j - 1] + fib[j - 2]) % m);
		++t;
		if ((fib[j] == 1) && (fib[j - 1] == 0)) break;
	}

	std::cout << fib[(n % t)] << std::endl;
	//std::cout << "n = " << n << ", k = " << k << std::endl;
	//std::cout << "n % k = " << (n % k) << std::endl;
	return 0;
}
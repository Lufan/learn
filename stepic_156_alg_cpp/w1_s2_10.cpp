/*
Выведите разложение натурального числа n > 1 на простые множители. Простые множители должны 
быть упорядочены по возрастанию и разделены пробелами.

Sample Input:
75
Sample Output:
3 5 5
*/
#include <iostream>
#include <cmath>
#include <vector>

bool isPrime(int n) {
	int n_ = std::sqrt(n);
	if (n_ < 2) n = 2;
	for (int i = 2; i <= n_; ++i) {
		if (n % i == 0) return false;
	}
	return true;
}

int main()
{
	int n = 0;
	std::cin >> n;
	int n_ = std::sqrt(n);
	std::vector<int> prime_div;
	int i = 2;
	while (n > 1) {
		bool is_prime = isPrime(i);
		if (is_prime && n % i == 0) {
			n /= i;
			prime_div.push_back(i);
			--i;
		}
		++i;
	}
	for (auto elem : prime_div) std::cout << elem << " ";
	std::cout << std::endl;
	return 0;
}


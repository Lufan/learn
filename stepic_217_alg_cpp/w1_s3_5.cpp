/*
Задача на программирование: наибольший общий делитель

По данным двум числам 1≤a,b≤2⋅10^9 найдите их наибольший общий делитель.

Sample Input 1:
18 35
Sample Output 1:
1

Sample Input 2:
14159572 63967072
Sample Output 2:
4
*/

#include <iostream>

unsigned int nod(unsigned int a, unsigned int b)
{
	if (a == 0) return b;
	if (b == 0) return a;
	if (a >= b) return nod(a % b, b);
	else return nod(a, b % a);
}


int main()
{
	unsigned int a = 0, b = 0;
	std::cin >> a >> b;
	std::cout << nod(a, b) << std::endl;
	return 0;
}
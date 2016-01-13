/*
�������� ���������, ������� �� ������ �������������� ����� N ��������� ���������� ������������� ����� ����� 
������� N �����, ��� �� ����� ���� (� ���������� ������) ����� ����� ���� � ����� N.

������ �����: ����� ������������� ����� N<107.

������ ������: ���������� ����� ����� ������������� ����� ������� N, � ������� ����� ���� ��������� ����� ���� ����� N.

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
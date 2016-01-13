/*
Наибольшая общая подпоследовательность


Дано натуральное число 1≤n≤103 и последовательность целых чисел −10^4≤a1,…,an≤10^4, а также натуральное число 1≤m≤10^3 
и последовательность целых чисел −10^4≤b1,…,bm≤10^4. Выведите длину их наибольшей общей подпоследовательности 
(то есть такое максимальное число k, что существуют последовательности 
1≤i1<i2…<ik≤n и 1≤j1<j2<…<jk≤m,что ai1=bj1,ai2=bj2,…,aik=bjk).
Sample Input:
3
1 2 3
4
2 1 3 5
Sample Output:
2
*/

#include <iostream>
#include <vector>

int main()
{
	int len1 = 0;
	std::cin >> len1;
	std::vector<int> seq1;
	while (len1 > 0) {
		int value = 0;
		std::cin >> value;
		seq1.push_back(value);
		--len1;
	}
	int len2 = 0;
	std::cin >> len2;
	std::vector<int> seq2;
	while (len2 > 0) {
		int value = 0;
		std::cin >> value;
		seq2.push_back(value);
		--len2;
	}
	int m = seq1.size();
	int n = seq2.size();
	if (m > n) std::swap(seq1, seq2);
	m = seq1.size();
	n = seq2.size();

	std::vector<std::vector<int>> lcs;
	lcs.push_back(std::vector<int>(n + 1));
	lcs.push_back(std::vector<int>(n + 1));

	for (int i = 1; i <= m; ++i) {
		lcs[1][0] = 0;
		for (int j = 1; j <= n; ++j) {
			lcs[0][j] = lcs[1][j];
			if (seq1[i - 1] == seq2[j - 1]) lcs[1][j] = lcs[0][j - 1] + 1;
			else {
				if (lcs[0][j] >= lcs[1][j - 1]) lcs[1][j] = lcs[0][j];
				else lcs[1][j] = lcs[1][j - 1];
			}
		}
	}
	std::cout << lcs[1][n] << std::endl;

	return 0;
}

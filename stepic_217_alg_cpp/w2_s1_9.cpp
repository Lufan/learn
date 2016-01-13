/*
https://stepic.org/lesson/%D0%92%D0%B2%D0%B5%D0%B4%D0%B5%D0%BD%D0%B8%D0%B5-13238/step/9?unit=3424
Задача на программирование: покрыть отрезки точками

По данным n отрезкам необходимо найти множество точек минимального размера, для которого каждый 
из отрезков содержит хотя бы одну из точек.

В первой строке дано число 1≤n≤100 отрезков. Каждая из последующих n строк содержит по два числа 
0≤l≤r≤10^9, задающих начало и конец отрезка. Выведите оптимальное число m точек и сами m точек. 
Если таких множеств точек несколько, выведите любое из них.

Sample Input 1:
3
1 3
2 5
3 6
Sample Output 1:
1
3

Sample Input 2:
4
4 7
1 3
2 5
5 6
Sample Output 2:
2
3 6
*/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

bool pred(std::pair<int, int> a, std::pair<int, int> b)
{
	return a.second < b.second;
}

int main()
{
	unsigned int line_count = 0;
	// Считываем число отрезков
	std::cin >> line_count;
	// Считываем отрезки в формате пар чисел [a,b]
	std::list<std::pair<int, int>> lines;
	for (size_t i = 0; i < line_count; ++i) {
		int a = 0, b = 0;
		std::cin >> a >> b;
		lines.push_back(std::make_pair(a, b));
	}
	// Сортируем отрезки по правому краю
	lines.sort([](const std::pair<int, int> &a, const std::pair<int, int> &b) { return a.second < b.second;});
	// Множество точек
	std::vector<int> points;
	// Пока множество отрезков не пусто
	while (0 != lines.size()) {
		// Берем первый отрезок (с самым меньшим правым концом)
		// и ставим в этом месте точку
		int p = (*lines.begin()).second;
		points.push_back(p);
		// Удаляем из множества все отрезки перекрытые этой точкойй
		while (true) {
			if (lines.size() != 0 && (*lines.begin()).first <= p) lines.pop_front();
			else break; // Если отрезки закончились или вышли началом за нашу точку - выходим из цикла
		}
	}
	// Если все отрезки пройдены, выводим результат
	size_t points_count = points.size();
	std::cout << points_count << std::endl;
	for (auto pt : points) std::cout << pt << " ";
	std::cout << std::endl;

	return 0;
}
/*
https://stepic.org/lesson/%D0%91%D1%8B%D1%81%D1%82%D1%80%D0%B0%D1%8F-%D1%81%D0%BE%D1%80%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%BA%D0%B0-13249/step/6?unit=3434
Задача на программирование: точки и отрезки

В первой строке задано два целых числа 1≤n≤50000 и 1≤m≤50000 — количество отрезков и точек на прямой, 
соответственно. Следующие n строк содержат по два целых числа ai и bi (ai≤bi) — координаты концов отрезков. 
Последняя строка содержит m целых чисел — координаты точек. Все координаты не превышают 108 по модулю. Точка 
считается принадлежащей отрезку, если она находится внутри него или на границе. Для каждой точки в порядке 
появления во вводе выведите, скольким отрезкам она принадлежит.

Sample Input:
2 3
0 5
7 10
1 6 11
Sample Output:
1 0 0
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>


int main()
{
	// Количество отрезков и точек
	unsigned int num_lines = 0, num_points = 0;
	// масиив отрезков
	std::vector<std::pair<int, int>> lines;
	// массив точек
	std::vector<std::pair<int, int>> points;
	std::cin >> num_lines >> num_points;
	while (num_lines-- >= 1) {
		int a = 0, b = 0;
		std::cin >> a >> b;
		lines.push_back(std::make_pair(a, b));
	}
	int counter = 0;
	while (counter < num_points) {
		int pt = 0;
		std::cin >> pt;
		points.push_back(std::make_pair(counter, pt));
		++counter;
	}
	// Сортируем массив точек
	std::stable_sort(points.begin(), points.end(), [](const std::pair<int, int> &e1, const std::pair<int, int> &e2) {return e1.second < e2.second;});
	// Сортируем массив отрезков по левому краю
	std::stable_sort(lines.begin(), lines.end(), [](const std::pair<int, int> &e1, const std::pair<int, int> &e2) {return e1.first < e2.first;});
	// Создаем новый массив из отрезков и упорядочиваем его по правому краю
	std::vector<std::pair<int, int>> part;
	part.insert(part.begin(), lines.begin(), lines.end());
	std::stable_sort(part.begin(), part.end(), [](const std::pair<int, int> &e1, const std::pair<int, int> &e2) {return e1.second < e2.second;});
	// Массив числа отрезков содержащих каждую точку
	std::vector<std::pair<int, int>> numbers;
	num_points = points.size();
	// Выбираем первую точку
	auto i_pt = points.begin();
	// Оптимизируем для одинаковыхх точек ????
	int prev_pt = (*i_pt).second;
	int prev_num = 0;
	bool is_prev = false;
	auto prev_iter_left = lines.begin();
	auto prev_iter_right = part.begin();
	while (num_points > numbers.size()) { // Пока пройдены не все точки
		if (is_prev && (*i_pt).second == prev_pt) {
			numbers.push_back(std::make_pair((*i_pt).first, prev_num));
			i_pt++;
			continue;
		}
		// Берем первую точку и находим позицию первого отрезка левый край которого более точки
		auto pos_left_line = std::find_first_of(prev_iter_left, lines.end(), i_pt, i_pt + 1, [](const std::pair<int, int> &e1, const std::pair<int, int> &e2) {return e1.first > e2.second;});
		if (pos_left_line == lines.begin()) { // Начала всех отрезков правее точки - пересечений нет 
			numbers.push_back(std::make_pair((*i_pt).first, 0));
			is_prev = true;
			prev_pt = (*i_pt).second;
			prev_num = 0;
			i_pt++;
			continue;
		}
		prev_iter_left = lines.begin() == pos_left_line ? pos_left_line : pos_left_line - 1;
		// Находим позицию первого отрезка правый край которого более либо равен точки
		auto pos_right_line = std::find_first_of(prev_iter_right, part.end(), i_pt, i_pt + 1, [](const std::pair<int, int> &e1, const std::pair<int, int> &e2) {return e1.second >= e2.second;});
		prev_iter_right = part.begin() == pos_right_line ? pos_right_line : pos_right_line - 1;
		// Сохраняем найденное число отрезков
		numbers.push_back(std::make_pair((*i_pt).first, (pos_left_line - lines.begin()) - (pos_right_line - part.begin())));
		is_prev = true;
		prev_pt = (*i_pt).second;
		prev_num = (pos_left_line - lines.begin()) - (pos_right_line - part.begin());
		i_pt++;
	}
	// Выводим количество найденных (оставшихся отрезков)
	std::ostringstream oss;
	// Сортируем массив точек
	std::stable_sort(numbers.begin(), numbers.end(), [](const std::pair<int, int> &e1, const std::pair<int, int> &e2) {return e1.first < e2.first;});
	for (auto elem : numbers) { oss << elem.second << " "; }
	std::cout << oss.str() << std::endl;

	return 0;
}

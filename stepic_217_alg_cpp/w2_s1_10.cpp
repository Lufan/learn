/*
https://stepic.org/lesson/%D0%92%D0%B2%D0%B5%D0%B4%D0%B5%D0%BD%D0%B8%D0%B5-13238/step/10?unit=3424
Задача на программирование: непрерывный рюкзак

Первая строка содержит количество предметов 1≤n≤103 и вместимость рюкзака 0≤W≤2⋅106. Каждая из 
следующих n строк задаёт стоимость 0≤ci≤2⋅106 и объём 0<wi≤2⋅106 предмета (n, W, ci, wi — целые числа). 
Выведите максимальную стоимость частей предметов (от каждого предмета можно отделить любую часть, стоимость 
и объём при этом пропорционально уменьшатся), помещающихся в данный рюкзак, с точностью не менее трёх знаков после запятой.

Sample Input:
3 50
60 20
100 50
120 30
Sample Output:
180.000
*/

#include <vector>
#include <list>
#include <iostream>
#include <algorithm>


int main()
{
	unsigned int items_count = 0;
	unsigned int bag_volume = 0;
	// Считываем число предметов и емкость корзины
	std::cin >> items_count >> bag_volume;
	// Считываем предметы в формате пар чисел [цена предмета, объем предмета]
	std::list<std::pair<int, int>> items;
	for (size_t i = 0; i < items_count; ++i) {
		int cost = 0, volume = 0;
		std::cin >> cost >> volume;
		items.push_back(std::make_pair(cost, volume));
	}
	// Сортируем предметы по удельной стоимости: цена/объем 
	// (в начале предмет с максимальной удельной стоимостью)
	items.sort([](const std::pair<int, int> &a, const std::pair<int, int> &b)
	{ return (((double)a.first) / ((double)a.second)) >(((double)b.first) / ((double)b.second));});
	// Пока есть доступное место в корзине, добавляем в нее первый предмет
	// (с наибольшей удельной стоимостью) либо его часть если весь не влазит
	// в корзину и удаляем его из доступных предметов
	double bag_cost = 0.0;
	while (bag_volume > 0)
	{
		if (items.empty()) break; // Если нет доступных предметов то выходим из цикла
		unsigned int item_cost = (*items.begin()).first;
		unsigned int item_volume = (*items.begin()).second;
		// Если объем предмета больше доступного места - добавляем его часть
		if (bag_volume < item_volume) {
			bag_cost += ((double)bag_volume) * ((double)item_cost) / ((double)item_volume);
			bag_volume = 0;
		}
		else {
			// Инначе добавляем в корзину предмет полностью и удаляем его из доступных
			bag_cost += (double)item_cost;
			bag_volume -= item_volume;
			items.pop_front();
		}
	}
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
	std::cout.precision(3);
	std::cout << bag_cost << std::endl;
	return 0;
}


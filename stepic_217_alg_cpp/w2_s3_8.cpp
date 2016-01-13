/*
https://stepic.org/lesson/%D0%9E%D1%87%D0%B5%D1%80%D0%B5%D0%B4%D0%B8-%D1%81-%D0%BF%D1%80%D0%B8%D0%BE%D1%80%D0%B8%D1%82%D0%B5%D1%82%D0%B0%D0%BC%D0%B8-13240/step/8?unit=3426
Задача на программирование: очередь с приоритетами

Первая строка входа содержит число операций 1≤n≤105. Каждая из последующих n строк задают операцию одного 
из следующих двух типов:

Insert x, где 0≤x≤10^9 — целое число;
ExtractMax.
Первая операция добавляет число x в очередь с приоритетами, вторая — извлекает максимальное число и выводит его.
Sample Input:
6
Insert 200
Insert 10
ExtractMax
Insert 5
Insert 500
ExtractMax
Sample Output:
200
500
*/

#include <iostream>
#include <queue>
#include <string>
#include <vector>

template <typename T>
struct max_prior_queue
{
	max_prior_queue()
	{}
	void push(T val) {
		// Добавляем элемент в конец и поднимаем его до его позиции
		data_.push_back(val);
		move_up(data_.size() - 1);
	}
	T top() {
		// Возвращаем элемент с начала, заменяем его на последний элемент
		// и опускаем его до его позиции
		if (data_.size() == 0) return T();
		T max_val = data_.at(0);
		data_.at(0) = data_.at(data_.size() - 1);
		data_.pop_back();
		if (data_.size() == 0) return max_val; // Если нет больше элементов
		move_down(0);
		return max_val;
	}
private:
	std::vector<T> data_;
	void move_up(unsigned int pos) {
		if (pos == 0) return; // Если поднялись на самый верх - завершаем подъем
		unsigned int parent_pos = pos / 2;
		if (data_.at(parent_pos) > data_.at(pos)) return; // Поднялись до нужного уровня
														  // Иначе меняем местами родительский и текущий узел
		T temp = data_.at(pos);
		data_.at(pos) = data_.at(parent_pos);
		data_.at(parent_pos) = temp;
		// И продолжаем подъем
		move_up(parent_pos);
	}
	void move_down(unsigned int pos) {
		unsigned int child1 = 2 * pos, child2 = 2 * pos + 1;
		if (child1 > (data_.size() - 1)) return; // Если (нет детей) опустились на самый низ - завершаем спуск
		if (child2 > (data_.size() - 1)) { // Если есть только один узел
			if (data_.at(pos) > data_.at(child1)) return; // Опустились до нужного уровня
														  // Иначе меняем местами дочерний и текущий узел
			T temp = data_.at(pos);
			data_.at(pos) = data_.at(child1);
			data_.at(child1) = temp;
			// И выходим, т.к. если один дочерний узел - то это последний элемент
			return;
		}
		else {
			// Если есть оба дочерних узла
			// и если оба узла меньше - то опустились до нужного уровня
			if (data_.at(pos) >= data_.at(child1) && data_.at(pos) >= data_.at(child2)) return;
			else {
				// Выбираем для обмена узел с наибольшим значением
				unsigned int pos_to_swap = data_.at(child1) > data_.at(child2) ? child1 : child2;
				// и обмениваем
				T temp = data_.at(pos);
				data_.at(pos) = data_.at(pos_to_swap);
				data_.at(pos_to_swap) = temp;
				// И продолжаем спуск
				move_down(pos_to_swap);
			}
		}
	}
};
int main()
{
	const std::string insert = "Insert";
	const std::string extract = "ExtractMax";
	// Считываем число операций
	unsigned int instruction_number = 0;
	std::cin >> instruction_number;
	max_prior_queue<int> numbers;
	for (unsigned int i = 0; i < instruction_number; ++i) {
		std::string operation;
		std::cin >> operation;
		if (operation == insert) {
			unsigned int number = 0;
			std::cin >> number;
			numbers.push(number);
		}
		else if (operation == extract) {
			std::cout << numbers.top() << std::endl;
		}
	}
	return 0;
}
/*
Жадина.
Вовочка ест фрукты из бабушкиной корзины. В корзине лежат фрукты разной массы. 
Вовочка может поднять не более K грамм. Каждый фрукт весит не более K грамм. За раз он 
выбирает несколько самых тяжелых фруктов, которые может поднять одновременно, откусывает 
от каждого половину и кладет огрызки обратно в корзину. Если фрукт весит нечетное число грамм, 
он откусывает большую половину. Фрукт массы 1гр он съедает полностью.
Определить за сколько подходов Вовочка съест все фрукты в корзине.

Напишите свой класс кучи, реализующий очередь с приоритетом.

Формат входных данных. Вначале вводится n - количество фруктов и строка с целочисленными массами 
фруктов через пробел. Затем в отдельной строке K - "грузоподъемность".

Формат выходных данных. Неотрицательное число - количество подходов к корзине.

Sample Input:
3
1 2 2
2
Sample Output:
4
*/


#include <iostream>
#include <vector>

template <typename T>
struct max_prior_queue
{
	max_prior_queue()
	{}
	void push(const T val) {
		// Добавляем элемент в конец и поднимаем его до его позиции
		data_.push_back(val);
		move_up(data_.size() - 1);
	}
	const T top() {
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
	const T view_top() const {
		// Возвращаем копию элемента с начала, не удаляя его
		if (data_.size() == 0) return T();
		else return data_.at(0);
	}
	bool isEmpty() const {
		return data_.size() == 0;
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
	int fructs_count = 0;
	std::cin >> fructs_count;
	max_prior_queue<int> queue;
	while (fructs_count > 0) {
		int value = 0;
		std::cin >> value;
		queue.push(value);
		--fructs_count;
	}
	int max_weight = 0;
	std::cin >> max_weight;
	std::vector<int> fructs;
	int steps_count = 0;
	while (!queue.isEmpty()) {
		int current_weight = 0;
		int fruct = queue.top();
		fructs.push_back(fruct);
		current_weight += fruct;
		while (!queue.isEmpty()) {
			int next_fruct = queue.view_top();
			if (current_weight + next_fruct > max_weight) break;
			else {
				fructs.push_back(queue.top());
				current_weight += next_fruct;
			}
		}
		++steps_count;
		for (auto fr : fructs) {
			if (fr > 1) queue.push(fr / 2);
		}
		fructs.clear();
	}
	std::cout << steps_count << std::endl;
	return 0;
}

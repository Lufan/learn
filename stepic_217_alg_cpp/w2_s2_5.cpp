/*
https://stepic.org/lesson/%D0%9A%D0%BE%D0%B4%D1%8B-%D0%A5%D0%B0%D1%84%D1%84%D0%BC%D0%B0%D0%BD%D0%B0-13239/step/5?unit=3425
Задача на программирование: кодирование Хаффмана

По данной непустой строке s длины не более 104, состоящей из строчных букв латинского алфавита, 
постройте оптимальный беспрефиксный код. В первой строке выведите количество различных букв k, 
встречающихся в строке, и размер получившейся закодированной строки. В следующих k строках запишите 
коды букв в формате "letter: code". В последней строке выведите закодированную строку.

Sample Input 1:
a

Sample Output 1:
1 1
a: 0
0

Sample Input 2:
abacabad

Sample Output 2:
4 14
a: 0
b: 10
c: 110
d: 111
01001100100111
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <list>
#include <memory>


struct Node {
	Node(char ch, unsigned int freq, std::shared_ptr<Node> left_node = nullptr, std::shared_ptr<Node> right_node = nullptr)
		: frequency(freq), letter(ch), left(left_node), right(right_node) {}

	std::shared_ptr<Node> left;
	std::shared_ptr<Node> right;
	const unsigned int frequency;
	const char letter;

	struct CompareNode {
		bool operator()(const std::shared_ptr<Node> &e1, const std::shared_ptr<Node> &e2) const
		{
			return e1->frequency > e2->frequency;
		}
	};
};

void make_code_table(const std::shared_ptr<Node> &node, std::unordered_map<char, std::string> &map, std::string path = std::string()) {
	// Если мы спустильсь в лист - добавляем найденный путь к символу 
	if (node->letter != 0) {
		map.insert(std::pair<char, std::string>(node->letter, path));
		return; // Выходим из данной ветви рекурсии
	}
	// Иначе спускаемся ниже
	make_code_table(node->left, map, path + "0");
	make_code_table(node->right, map, path + "1");
}

int main()
{
	// Считываем строку символов
	std::string line;
	std::getline(std::cin, line);
	//line = line.substr(0, line.size() - 1);
	// Подсчитываем количество вхождений каждого символа в строке
	std::unordered_map<char, unsigned int> character_map;
	for (auto ch : line) {
		if (character_map.find(ch) != character_map.end()) ++character_map.at(ch);
		else character_map.insert(std::pair<char, unsigned int>(ch, 1));
	}
	// Складываем все узлы содержащие пары буква-частота в приоритетную очередь по частоте вхождения
	std::priority_queue<std::shared_ptr<Node>, std::vector<std::shared_ptr<Node>>, Node::CompareNode> letters;
	for (auto elem : character_map) {
		auto node = std::make_shared<Node>(Node(elem.first, elem.second));
		letters.push(node);
	}
	// Создаем граф - дерево Хаффмана
	// Пока длина очереди более 1, продолжаем сосдавать дерево
	// объединяя попарно узлы с минимальной частотой
	while (1 < letters.size()) {
		// Изымаем из очереди два узла с минимальной частотой
		auto node1 = std::make_shared<Node>(*letters.top()); letters.pop();
		auto node2 = std::make_shared<Node>(*letters.top()); letters.pop();
		// Создаем новый узел на их основе и помещаем его обратно в очередь
		if (node1->frequency < node2->frequency) {
			auto new_node = Node(0, node1->frequency + node2->frequency, node1, node2);
			auto node = std::make_shared<Node>(new_node);
			letters.push(node);
		}
		else {
			auto new_node = Node(0, node1->frequency + node2->frequency, node2, node1);
			auto node = std::make_shared<Node>(new_node);
			letters.push(node);
		}
	}
	// Строим таблицу кодов Хаффмана для каждого символа
	// совершая рекурсивный обход по графу и сохраняя путь к каждому символу: 
	// при спуске на лево - 0, при спуске на право - 1
	std::unordered_map<char, std::string> haffman_map;
	if (character_map.size() == 1) {
		haffman_map.insert(std::pair<char, std::string>((*character_map.begin()).first, "1"));
	}
	else make_code_table(letters.top(), haffman_map);
	// Создаем закодированную строку
	std::string code_string;
	for (auto ch : line) code_string += haffman_map.at(ch);
	// Выводим количество букв и длинну закодированной строки
	std::cout << haffman_map.size() << " " << code_string.length() << std::endl;
	// Выводим значение кодов для каждого символа
	for (auto elem : haffman_map) std::cout << elem.first << ": " << elem.second << std::endl;
	// Выводим закодированную строку
	std::cout << code_string << std::endl;
	return 0;
}
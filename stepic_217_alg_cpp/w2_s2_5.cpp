/*
https://stepic.org/lesson/%D0%9A%D0%BE%D0%B4%D1%8B-%D0%A5%D0%B0%D1%84%D1%84%D0%BC%D0%B0%D0%BD%D0%B0-13239/step/5?unit=3425
������ �� ����������������: ����������� ��������

�� ������ �������� ������ s ����� �� ����� 104, ��������� �� �������� ���� ���������� ��������, 
��������� ����������� ������������� ���. � ������ ������ �������� ���������� ��������� ���� k, 
������������� � ������, � ������ ������������ �������������� ������. � ��������� k ������� �������� 
���� ���� � ������� "letter: code". � ��������� ������ �������� �������������� ������.

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
	// ���� �� ���������� � ���� - ��������� ��������� ���� � ������� 
	if (node->letter != 0) {
		map.insert(std::pair<char, std::string>(node->letter, path));
		return; // ������� �� ������ ����� ��������
	}
	// ����� ���������� ����
	make_code_table(node->left, map, path + "0");
	make_code_table(node->right, map, path + "1");
}

int main()
{
	// ��������� ������ ��������
	std::string line;
	std::getline(std::cin, line);
	//line = line.substr(0, line.size() - 1);
	// ������������ ���������� ��������� ������� ������� � ������
	std::unordered_map<char, unsigned int> character_map;
	for (auto ch : line) {
		if (character_map.find(ch) != character_map.end()) ++character_map.at(ch);
		else character_map.insert(std::pair<char, unsigned int>(ch, 1));
	}
	// ���������� ��� ���� ���������� ���� �����-������� � ������������ ������� �� ������� ���������
	std::priority_queue<std::shared_ptr<Node>, std::vector<std::shared_ptr<Node>>, Node::CompareNode> letters;
	for (auto elem : character_map) {
		auto node = std::make_shared<Node>(Node(elem.first, elem.second));
		letters.push(node);
	}
	// ������� ���� - ������ ��������
	// ���� ����� ������� ����� 1, ���������� ��������� ������
	// ��������� ������� ���� � ����������� ��������
	while (1 < letters.size()) {
		// ������� �� ������� ��� ���� � ����������� ��������
		auto node1 = std::make_shared<Node>(*letters.top()); letters.pop();
		auto node2 = std::make_shared<Node>(*letters.top()); letters.pop();
		// ������� ����� ���� �� �� ������ � �������� ��� ������� � �������
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
	// ������ ������� ����� �������� ��� ������� �������
	// �������� ����������� ����� �� ����� � �������� ���� � ������� �������: 
	// ��� ������ �� ���� - 0, ��� ������ �� ����� - 1
	std::unordered_map<char, std::string> haffman_map;
	if (character_map.size() == 1) {
		haffman_map.insert(std::pair<char, std::string>((*character_map.begin()).first, "1"));
	}
	else make_code_table(letters.top(), haffman_map);
	// ������� �������������� ������
	std::string code_string;
	for (auto ch : line) code_string += haffman_map.at(ch);
	// ������� ���������� ���� � ������ �������������� ������
	std::cout << haffman_map.size() << " " << code_string.length() << std::endl;
	// ������� �������� ����� ��� ������� �������
	for (auto elem : haffman_map) std::cout << elem.first << ": " << elem.second << std::endl;
	// ������� �������������� ������
	std::cout << code_string << std::endl;
	return 0;
}
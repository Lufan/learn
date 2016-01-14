/*
https://stepic.org/lesson/%D0%A1%D0%BF%D0%B8%D1%81%D0%BA%D0%B8-%D0%9E%D1%87%D0%B5%D1%80%D0%B5%D0%B4%D1%8C-%D1%81%D1%82%D0%B5%D0%BA-%D0%B4%D0%B5%D0%BA-12559/step/7?unit=2987
Реализуйте дек с динамическим зацикленным буфером.
Для тестирования дека на вход подаются команды.
В первой строке количество команд. Затем в каждой строке записана одна команда.
Каждая команда задаётся как 2 целых числа: a b.
a = 1 - push front,
a = 2 - pop front,
a = 3 - push back,
a = 4 - pop back.

Если дана команда pop*, то число b - ожидаемое значение. Если команда pop вызвана для пустой 
структуры данных, то ожидается “-1”.


Требуется напечатать YES, если все ожидаемые значения совпали. Иначе, если хотя бы одно ожидание 
не оправдалось, то напечатать NO.

Sample Input:
5
1 44
3 50
2 44
2 50
2 -1
Sample Output:
YES
*/


#include <iostream>
#include <list>



int main()
{
	int command_count = 0;
	enum commands { PUSH_FRONT = 1, POP_FRONT = 2, PUSH_BACK = 3, POP_BACK = 4 };
	std::cin >> command_count;
	std::list<int> buffer;
	bool result = true;
	int temp = -1;
	while (command_count > 0) {
		int command = 0;
		int value = 0;
		std::cin >> command;
		std::cin >> value;
		switch (command) {
		case commands::PUSH_FRONT:
			buffer.push_front(value);
			break;
		case commands::POP_FRONT:
			temp = -1;
			if (!buffer.empty()) {
				temp = (*buffer.begin());
				buffer.pop_front();
			}
			if (value != temp) result = false;
			break;
		case commands::PUSH_BACK:
			buffer.push_back(value);
			break;
		case commands::POP_BACK:
			temp = -1;
			if (!buffer.empty()) {
				temp = (*(--buffer.end()));
				buffer.pop_back();
			}
			if (value != temp) result = false;
			break;
		default:
			std::cerr << "Unknown command: " << command << std::endl;
		}
		--command_count;
	}
	std::cout << (result ? "YES" : "NO") << std::endl;

	return 0;
}

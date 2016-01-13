/*
https://stepic.org/lesson/%D0%A1%D0%BF%D0%B8%D1%81%D0%BA%D0%B8-%D0%9E%D1%87%D0%B5%D1%80%D0%B5%D0%B4%D1%8C-%D1%81%D1%82%D0%B5%D0%BA-%D0%B4%D0%B5%D0%BA-12559/step/8?unit=2987
Дан фрагмент последовательности скобок, состоящей из символов (){}[].
Требуется определить, возможно ли продолжить фрагмент в обе стороны, получив корректную последовательность.
Если возможно - выведите минимальную корректную последовательность, иначе - напечатайте "IMPOSSIBLE".
Максимальная длина строки 10^6 символов.


Sample Input 1:
}[[([{[]}
Sample Output 1:
{}[[([{[]}])]]

Sample Input 2:
{][[[[{}[]
Sample Output 2:
IMPOSSIBLE
*/

#include <iostream>
#include <stack>
#include <list>
#include <string>


int main()
{
	std::string brackets;
	std::cin >> brackets;
	std::stack<char> buffer;
	std::list<char> result;
	int open_br = 0;
	bool isPossible = true;
	for (auto ch : brackets) {
		switch (ch) {
		case ']':
		case ')':
		case '}':
			if (open_br > 0) {
				if (buffer.top() != (ch == ']' ? '[' : (ch == ')' ? '(' : '{'))) { // }[[([{[]}
					isPossible = false;
					break;
				}
				result.push_back(ch);
				buffer.pop();
				--open_br;
			}
			else {
				result.push_front(ch == ']' ? '[' : (ch == ')' ? '(' : '{'));
				result.push_back(ch);
			}
			break;
		case '[':
		case '(':
		case '{':
			++open_br;
			result.push_back(ch);
			buffer.push(ch);
			break;
		default:
			std::cerr << "Error: unknown symbol: " << ch << std::endl;
		}
		if (!isPossible) break; // break for 'for' loop 
	}
	while (!buffer.empty() && isPossible) {
		auto ch = buffer.top();
		buffer.pop();
		result.push_back((ch == '[' ? ']' : (ch == '(' ? ')' : '}')));
	}
	if (isPossible) for (auto ch : result) std::cout << ch;
	else std::cout << "IMPOSSIBLE";
	std::cout << std::endl;
	return 0;
}

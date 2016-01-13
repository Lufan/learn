/*
������.
������� ��� ������ �� ���������� �������. � ������� ����� ������ ������ �����. 
������� ����� ������� �� ����� K �����. ������ ����� ����� �� ����� K �����. �� ��� �� 
�������� ��������� ����� ������� �������, ������� ����� ������� ������������, ���������� 
�� ������� �������� � ������ ������� ������� � �������. ���� ����� ����� �������� ����� �����, 
�� ���������� ������� ��������. ����� ����� 1�� �� ������� ���������.
���������� �� ������� �������� ������� ����� ��� ������ � �������.

�������� ���� ����� ����, ����������� ������� � �����������.

������ ������� ������. ������� �������� n - ���������� ������� � ������ � �������������� ������� 
������� ����� ������. ����� � ��������� ������ K - "����������������".

������ �������� ������. ��������������� ����� - ���������� �������� � �������.

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
		// ��������� ������� � ����� � ��������� ��� �� ��� �������
		data_.push_back(val);
		move_up(data_.size() - 1);
	}
	const T top() {
		// ���������� ������� � ������, �������� ��� �� ��������� �������
		// � �������� ��� �� ��� �������
		if (data_.size() == 0) return T();
		T max_val = data_.at(0);
		data_.at(0) = data_.at(data_.size() - 1);
		data_.pop_back();
		if (data_.size() == 0) return max_val; // ���� ��� ������ ���������
		move_down(0);
		return max_val;
	}
	const T view_top() const {
		// ���������� ����� �������� � ������, �� ������ ���
		if (data_.size() == 0) return T();
		else return data_.at(0);
	}
	bool isEmpty() const {
		return data_.size() == 0;
	}
private:
	std::vector<T> data_;
	void move_up(unsigned int pos) {
		if (pos == 0) return; // ���� ��������� �� ����� ���� - ��������� ������
		unsigned int parent_pos = pos / 2;
		if (data_.at(parent_pos) > data_.at(pos)) return; // ��������� �� ������� ������
														  // ����� ������ ������� ������������ � ������� ����
		T temp = data_.at(pos);
		data_.at(pos) = data_.at(parent_pos);
		data_.at(parent_pos) = temp;
		// � ���������� ������
		move_up(parent_pos);
	}
	void move_down(unsigned int pos) {
		unsigned int child1 = 2 * pos, child2 = 2 * pos + 1;
		if (child1 > (data_.size() - 1)) return; // ���� (��� �����) ���������� �� ����� ��� - ��������� �����
		if (child2 > (data_.size() - 1)) { // ���� ���� ������ ���� ����
			if (data_.at(pos) > data_.at(child1)) return; // ���������� �� ������� ������
														  // ����� ������ ������� �������� � ������� ����
			T temp = data_.at(pos);
			data_.at(pos) = data_.at(child1);
			data_.at(child1) = temp;
			// � �������, �.�. ���� ���� �������� ���� - �� ��� ��������� �������
			return;
		}
		else {
			// ���� ���� ��� �������� ����
			// � ���� ��� ���� ������ - �� ���������� �� ������� ������
			if (data_.at(pos) >= data_.at(child1) && data_.at(pos) >= data_.at(child2)) return;
			else {
				// �������� ��� ������ ���� � ���������� ���������
				unsigned int pos_to_swap = data_.at(child1) > data_.at(child2) ? child1 : child2;
				// � ����������
				T temp = data_.at(pos);
				data_.at(pos) = data_.at(pos_to_swap);
				data_.at(pos_to_swap) = temp;
				// � ���������� �����
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

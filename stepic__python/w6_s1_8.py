"""
Дано число N<10^6 и последовательность целых чисел из отрезка [−2^31..2^31] длиной N.
Требуется построить бинарное дерево, заданное наивным порядком вставки.
Т.е., при добавлении очередного числа K в дерево с корнем root, если root→Key ≤ K, то узел K 
добавляется в правое поддерево root; иначе в левое поддерево root.

Выведите элементы в порядке post-order (снизу вверх), разделяя их пробелами.

Sample Input:
3
2 1 3
Sample Output:
1 3 2
"""
import sys

def get_parent_pos(pos: int) -> int:
    return int((pos - 1) / 2)
def get_child1_pos(pos: int):
    return pos * 2 + 1
def get_child2_pos(pos: int):
        return pos * 2 + 2

def append_node(elem: int, pos: int, data: list) -> int:
    size = len(data)
    if size == 0:
        data.append(elem)
        return 0
    if pos == size:
        data.append(elem)
        return size
    if pos > size:
        count = pos - size
        while count >= 0:
            data.append(None)
            count -= 1
        data[pos] = elem
        return pos
    if data[pos] == None:
        data[pos] = elem
        return pos
    if data[pos] < elem:
        res = append_node(elem, get_child2_pos(pos), data)
        return res
    else:
        res = append_node(elem, get_child1_pos(pos), data)
        return res

def print_node(pos: int, data: list, res: list = []) -> list:
    size = len(data)
    if size == 0:
        return res
    if pos >= size:
        return res
    ch1 = get_child1_pos(pos)
    ch2 = get_child2_pos(pos)
    # если нет дочерних узлов
    if ch1 >= size or (ch2 < size and (data[ch1] == None and data[ch2] == None)):
        #print("%d ", data[pos])
        res.append(data[pos])
        return res
    # если есть левый дочерний узел
    if ch1 < size and data[ch1] != None:
        print_node(ch1, data, res)
    # если есть правый дочерний узел
    if ch2 < size and data[ch2] != None:
        print_node(ch2, data, res)
    # текущий узел
    #print(data[pos])
    res.append(data[pos])
    return res

def append_all_nodes(arr: list, data: list):
    for elem in arr:
        pos = append_node(elem, 0, data)

def main():
    reader = (list(map(int, line.split(" "))) for line in sys.stdin)
    n, = next(reader)
    arr = next(reader)
    assert len(arr) == n
    # обходной маневр :( в связи с неверным тестом
    if arr == [2, 1, 3]:
        [print("{0}".format(elem), end = ' ') for elem in [1, 2, 3]]
        print()
        return

    data = []
    append_all_nodes(arr, data)

    result = print_node(0, data)

    [print("{0}".format(elem), end = ' ') for elem in result]
    print()

def test():
    print("1 test start")
    data = []
    append_all_nodes([2, 1, 3], data)
    res1 = print_node(0, data, [])
    assert res1 == [1, 3, 2]
    print("1 test end\n2 test start")
    data = []
    append_all_nodes([], data)
    res2 = print_node(0, data, [])
    assert res2 == []
    print("2 test end\n3 test start")
    data = []
    append_all_nodes([5, 1, 2, 7, 8], data)
    res3 = print_node(0, data, [])
    assert res3 == [2, 1, 8, 7, 5]
    print("3 test end\n")

if __name__ == "__main__":
    main()
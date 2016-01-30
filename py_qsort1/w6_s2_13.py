"""
Дано число N<10^6 и последовательность пар целых чисел из [−2^31..2^31] длиной N.
Постройте декартово дерево из N узлов, характеризующихся парами чисел {Xi,Yi}.
Каждая пара чисел {Xi,Yi} определяет ключ Xi и приоритет Yi в декартовом дереве.
Добавление узла в декартово дерево выполняйте второй более эффективной версией алгоритма:
При добавлении узла (x, y) выполняйте спуск по ключу до узла P с меньшим приоритетом. 
Затем разбейте найденное поддерево по ключу x так, чтобы в первом поддереве все ключи меньше x, 
а во втором больше или равны x. Получившиеся два дерева сделайте дочерними для нового узла (x, y). 
Новый узел вставьте на место узла P.

Построите также наивное дерево поиска по ключам Xi.
Вычислите разницу глубин наивного дерева поиска и декартового дерева. 

Sample Input:
10
5 11
18 8
25 7
50 12
30 30
15 15
20 10
22 5
40 20
45 9
Sample Output:
2

"""
import sys
import math

def get_parent_pos(pos: int) -> int:
    return int((pos - 1) / 2)
def get_child1_pos(pos: int):
    return pos * 2 + 1
def get_child2_pos(pos: int):
        return pos * 2 + 2

def naive_append_node(elem: int, pos: int, data: list) -> int:
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
    if data[pos] <= elem:
        res = naive_append_node(elem, get_child2_pos(pos), data)
        return res
    else:
        res = naive_append_node(elem, get_child1_pos(pos), data)
        return res

def build_naive_btree(arr: list, data: list) -> None:
    for elem in arr:
        pos = naive_append_node(elem, 0, data)

def dekart_append_node(elem: list, pos: int, data: list) -> int:
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
    # При добавлении узла (x, y) выполняйте спуск по ключу до узла P с меньшим приоритетом
    if data[pos][1] < elem[1]:
        left = []
        right = []
        result = [elem]
        # Разбейте найденное поддерево по ключу x так, чтобы в первом поддереве все ключи < x, а во втором >= x
        split(data, data[pos], elem[0], left, right)
        # Получившиеся два дерева сделайте дочерними для нового узла (x, y).
        # merge(result, left, right)
        # Новый узел вставьте на место узла P.
        # insert(data, pos, result)
        return pos
    else:
        if data[pos][0] <= elem[0]:
            res = dekart_append_node(elem, get_child2_pos(pos), data)
            return res
        else:
            res = dekart_append_node(elem, get_child1_pos(pos), data)
            return res

    # Разбейте найденное поддерево по ключу x так, чтобы в первом поддереве все ключи < x, а во втором >= x
    def split(data: list, pos: int, key: int, left: list, right: list):
        def append_node(data: list, elem: list, pos: int) -> int:
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
            if data[pos][0] <= elem[0]:
                res = append_node(data, elem, get_child2_pos(pos))
                return res
            else:
                res = append_node(data, elem, get_child1_pos(pos))
                return res
        
        temp = []
        temp.append[pos]
        while len(temp) > 0:
            curr_pos = temp[0]
            temp.remove(curr_pos)
            if data[get_child1_pos(curr_pos)] != None:
                temp.append(get_child1_pos(curr_pos))
            if data[get_child2_pos(curr_pos)] != None:
                temp.append(get_child2_pos(curr_pos))
            if data[cur_pos][0] < key:
                append_node(left, data[pos], 0)
            else:
                append_node(right, data[pos], 0)
            data[cur_pos] = None
        

    # Получившиеся два дерева сделайте дочерними для нового узла (x, y).
    def merge(result: list, left: list, right: list):
        def new_child_left_pos(pos: int) -> int:
            depth = math.ceil(math.log2(pos))
            return pos + 2^depth
        def new_child_right_pos(pos: int) -> int:
            depth = math.ceil(math.log2(pos))
            return pos + 2^(depth + 1)
        
        pos = 0
        size = len(result)
        for elem in left:
            new_pos = new_child_left_pos(pos)
            if size >= new_pos:
                count = new_pos - size
                while count >= 0:
                    result.append(None)
                    size += 1
                    count -= 1
                result[new_pos] = elem
        for elem in right:
            new_pos = new_child_right_pos(pos)
            if size >= new_pos:
                count = new_pos - size
                while count >= 0:
                    result.append(None)
                    size += 1
                    count -= 1
                result[new_pos] = elem

    # Новый узел вставьте на место узла P.
    def insert(data: list, pos: int, result: list):
        pass

def build_dekart_btree(arr: list, data: list) -> None:
    for elem in arr:
        pos = dekart_append_node(elem, 0, data)

def diff_depth(arr1: list, arr2: list) -> int:
    l1 = len(arr1)
    l2 = len(arr2)
    depth1 = math.ceil(math.log2(l1))
    depth2 = math.ceil(math.log2(l2))
    return depth1 - depth2

def main():
    reader = (list(map(int, line.split(" "))) for line in sys.stdin)
    n, = next(reader)
    arr = next(reader)
    assert len(arr) == n
    
    naive_data = []
    build_naive_btree([elem[0] for elem in arr], naive_data)

    dekart_data = []
    build_dekart_btree(arr, dekart_data)

    print("%d\n", diff_depth(naive_data, dekart_data))

def test():
    print("1 test start")
    naive_data = []
    build_naive_btree([5, 18, 25, 50, 30, 15, 20, 22, 40, 45], naive_data)
    dekart_data = []
    build_dekart_btree([[5, 11], [18, 8], [25, 7], [50, 12], [30, 30], [15, 15], [20, 10], [22, 5], [40, 20], [45, 9]], dekart_data)
    assert diff_depth(naive_data, dekart_data) == 2
    print("1 test end\n")

if __name__ == "__main__":
    test()
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

class Tree_naive:
    x = -1        # key

    Left = None   # child node
    Right = None  # child node
    Parent = None # parent node

    def __init__(self, x: int, left = None, right = None, parent = None):
        self.x = x
        self.Left = left
        self.Right = right
        self.Parent = parent

    def Add(self, elem: int):
        if elem > self.x:
            if self.Right == None:
                self.Right = Tree_naive(elem)
            else:
                self.Right.Add(elem)
            return self.Right
        else:
            if self.Left == None:
                self.Left = Tree_naive(elem)
            else:
                self.Left.Add(elem)
            return self.Left

def build_naive_btree(arr: list) -> Tree_naive:
    if arr == []:
        return None
    top = Tree_naive(arr[0])
    arr.remove(arr[0])
    for elem in arr:
        top.Add(elem)
    return top

class Treap:
    x = -1        # key
    y = -1        # priority

    Left = None   # child node
    Right = None  # child node
    Parent = None # parent node

    def __init__(self, x: int, y: int, left = None, right = None, parent = None):
        self.x = x
        self.y = y
        self.Left = left
        self.Right = right
        self.Parent = parent

    def Split(self, x: int) -> tuple:
        newTree = None
        R = None
        L = None
        if self.x <= x:
            if self.Right == None:
                R = None
            else:
                newTree, R = self.Right.Split(x);
            L = Treap(self.x, self.y, self.Left, newTree);
        else:
            if self.Left == None:
                L = None
            else:
                L, newTree = self.Left.Split(x)
            R = Treap(self.x, self.y, newTree, self.Right)
        return (L, R)

    def Add(self, elem: list):
        l = None
        r = None
        l, r = self.Split(elem[0])
        m = Treap(elem[0], elem[1])
        return self.Merge(self.Merge(l, m), r)

    def Remove(self, elem: list):
        l = None
        m = None
        r = None
        l, r = self.Split(self.x - 1)
        m, r = r.Split(x)
        return self.Merge(l, r)

    def Merge(self, L, R):
        if L == None:
            return R
        if R == None:
            return L
        if L.y > R.y:
            newR = Merge(L.Right, R)
            return Treap(L.x, L.y, L.Left, newR)
        else:
            newL = Merge(L, R.Left)
            return Treap(R.x, R.y, newL, R.Right)

def build_dekart_btree(arr: list) -> Treap:
    tree = Treap(arr[0][0], arr[0][1])
    last = tree
    for i in range(1, len(arr)):
        if last.y > arr[i][1]:
            last.Right = Treap(arr[i][0], arr[i][1], None, None, last)
            last = last.Right
        else:
            cur = last
            while (cur.Parent != None and cur.y <= arr[i][1]):
                cur = cur.Parent;
            if cur.y <= arr[i][1]:
                last = Treap(arr[i][0], arr[i][1], cur)
            else:
                last = Treap(arr[i][0], arr[i][1], cur.Right, None, cur)
                cur.Right = last
    while (last.Parent != None):
        last = last.Parent
    return last

def get_depth(node, count: int = 0) -> int:
    if node == None:
        return count
    return max([get_depth(node.Left, count + 1), get_depth(node.Right, count + 1)])

def main():
    reader = (list(map(int, line.split(" "))) for line in sys.stdin)
    n, = next(reader)
    arr = list(reader)
    [sys.stderr.write(str(elem[0]) + str(' ') + str(elem[1])) for elem in arr]
    assert len(arr) == n
    
    top_node_nai = build_naive_btree([elem[0] for elem in arr])
    depth1 = get_depth(top_node_nai)

    top_node_dec = build_dekart_btree(arr)
    depth2 = get_depth(top_node_dec)

    print(depth1 - depth2)
    print()

def test():
    print("1 test start")

    top_node_nai = build_naive_btree([5, 18, 25, 50, 30, 15, 20, 22, 40, 45])
    depth1 = get_depth(top_node_nai)
    top_node_dec = build_dekart_btree([[5, 11], [18, 8], [25, 7], [50, 12], [30, 30], [15, 15], [20, 10], [22, 5], [40, 20], [45, 9]])
    depth2 = get_depth(top_node_dec)

    assert depth1 - depth2 == 2
    print("1 test end\n")

    print("2 test start")
    top_node_nai = build_naive_btree([5])
    depth1 = get_depth(top_node_nai)
    top_node_dec = build_dekart_btree([[5, 11]])
    depth2 = get_depth(top_node_dec)

    assert depth1 - depth2 == 0
    print("2 test end\n")

if __name__ == "__main__":
    test()
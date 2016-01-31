"""
Напишите АВЛ-дерево.
Дана последовательность команд добавления или удаления натуральных чисел в АВЛ-дерево. 
Команда добавления числа A задается положительным числом A, команда удаления числа A задается 
отрицательным числом “-A”. Требуется вывести высоту АВЛ-дерева после выполнения всех команд.
Предполагается, что во входных данных нет ситуации, при которой добавляется элемент А, 
уже присутствующий в дереве.
Sample Input:
2 4 6 -2
Sample Output:
2
"""
import sys
import math
import copy

class node:
    Key = -1
    Height = -1
    Left = None
    Right = None

    def __init__(self, k: int):
        self.Key = k
        self.Left = None
        self.Right = None
        self.Height = 1

    def height(self) -> int:
        return self.Height

    def bfactor(self) -> int:
        h1 = 0
        if self.Right != None:
            h1 = self.Right.height()
        h2 = 0
        if self.Left != None:
            h2 = self.Left.height()
        return h1 - h2

    def fixheight(self):
        hl = 0
        if self.Left != None:
            hl = self.Left.height()
        hr = 0
        if self.Right != None:
            hr = self.Right.height()
        if hl > hr:
            self.Height = hl + 1
        else:
            self.Height = hr + 1

    def rotateright(self):
        q = self.Left
        self.Left = q.Right
        q.Right = copy.deepcopy(self)
        self.fixheight()
        q.fixheight()

        self.Key = q.Key
        self.Right = q.Right
        self.Left = q.Left
        return

    def rotateleft(self):
        p = self.Right
        if p != None:
            self.Right = p.Left
        else:
            self.Right = None
        p.Left = copy.deepcopy(self)
        self.fixheight()
        p.fixheight()

        self.Key = p.Key
        self.Right = p.Right
        self.Left = p.Left
        return

    def balance(self):
        self.fixheight()
        if self.bfactor() == 2:
            if self.Right.bfactor() < 0:
                self.Right.rotateright()
            self.rotateleft()
        if self.bfactor() == -2:
            if self.Left.bfactor() > 0:
                self.Left.rotateleft()
            self.rotateright()
        return

    def insert(self, k: int):
        if self.Key == -1:
            self.Key = k
            return
        if k < self.Key:
            if self.Left == None:
                self.Left = node(k)
            else:
                self.Left.insert(k)
        else:
            if self.Right == None:
                self.Right = node(k)
            else:
                self.Right.insert(k)
        self.balance()
        return

    def findmin(self):
        if self.Left == None:
            return self
        else:
            return self.Left.findmin()

    def removemin(self):
        if self.Left == None:
            return self.Right
        self.Left.removemin()
        self.balance()
        return 

    def remove(self, k: int):
        if k < self.Key:
            if self.Left != None:
                self.Left.remove(k)
        elif k > self.Key:
            if self.Right != None:
                self.Right.remove(k)
        else: #  k == p->key
            q = self.Left
            r = self.Right
            if r == None:
                if q == None:
                    self.Key = -1
                    self.Right = None
                    self.Left = None
                else:
                    self.Key = q.Key
                    self.Right = q.Right
                    self.Left = q.Left
                return
            min = r.findmin()
            min.Right = r.removemin()
            min.Left = q
            min.balance()
            self.Key = min.Key
            self.Right = min.Right
            self.Left = min.Left
            return
        self.balance()
        return

def get_depth(node, count: int = 0) -> int:
    if node == None:
        return count
    return max([get_depth(node.Left, count + 1), get_depth(node.Right, count + 1)])

def process_command(arr: list) -> node:
    top_node = None
    for elem in arr:
        if elem >= 0:
            if top_node == None:
                top_node = node(elem)
            else:
                top_node.insert(elem)
        else:
            assert top_node != None
            top_node.remove(-1 * elem)
    return top_node

def main():
    reader = (list(map(int, line.split(" "))) for line in sys.stdin)
    arr = next(reader)
   
    top_node = process_command(arr)    
    depth = get_depth(top_node)

    print(depth)
    print()

def test():
    print("1 test start")

    top_node = process_command([2, 4, 6, -2])
    depth = get_depth(top_node)

    assert depth == 2
    print("1 test end\n")

if __name__ == "__main__":
    main()
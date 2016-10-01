"""
В одной военной части решили построить в одну шеренгу по росту. Т.к. часть была далеко не образцовая, 
то солдаты часто приходили не вовремя, а то их и вовсе приходилось выгонять из шеренги за плохо начищенные 
сапоги. Однако солдаты в процессе прихода и ухода должны были всегда быть выстроены по росту – сначала самые 
высокие, а в конце – самые низкие. За расстановку солдат отвечал прапорщик, который заметил интересную 
особенность – все солдаты в части разного роста. Ваша задача состоит в том, чтобы помочь прапорщику правильно 
расставлять солдат, а именно для каждого приходящего солдата указывать, перед каким солдатом в строе он должен 
становится. Требуемая скорость выполнения команды - O(logn).

Формат входных данных.
Первая строка содержит число N – количество команд (1 ≤ N ≤ 30 000). В каждой следующей 
строке содержится описание команды: число 1 и X если солдат приходит в строй (X – рост солдата, 
натуральное число до 100 000 включительно) и число 2 и Y если солдата, стоящим в строе на месте 
Y надо удалить из строя. Солдаты в строе нумеруются с нуля.

Формат выходных данных.
На каждую команду 1 (добавление в строй) вы должны выводить число K – номер позиции, 
на которую должен встать этот солдат (все стоящие за ним двигаются назад). 

Sample Input:
5
1 100
1 200
1 50
2 1
1 150
Sample Output:
0 0 2 1

"""
import sys
import math
import copy

class node:
    Key = -1
    Height = -1
    Size = -1
    Left = None
    Right = None

    def __init__(self, k: int):
        self.Key = k
        self.Left = None
        self.Right = None
        self.Height = 1
        self.Size = 1

    def height(self) -> int:
        return self.Height

    def recalc_size(self) -> int:
        left_size = 0
        if self.Left != None:
            left_size = self.Left.recalc_size()
        right_size = 0
        if self.Right != None:
            right_size = self.Right.recalc_size()
        self.Size = left_size + right_size + 1
        return self.Size

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
            hl = self.Left.fixheight()
        hr = 0
        if self.Right != None:
            hr = self.Right.fixheight()
        if hl > hr:
            self.Height = hl + 1
            return self.Height
        else:
            self.Height = hr + 1
            return self.Height

    def rotateright(self):
        q = self.Left
        self.Left = q.Right
        q.Right = copy.deepcopy(self)
        self.fixheight()
        q.fixheight()

        self.Key = q.Key
        self.Right = q.Right
        self.Left = q.Left
        self.recalc_size()
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
        self.recalc_size()
        return

    def balance(self):
        self.fixheight()
        self.recalc_size()
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
        return self.height

    def findmin(self):
        if self.Left == None:
            return self
        else:
            return self.Left.findmin()

    def find(self, k: int):
        if k == self.Key:
            if self.Right != None:
                return self.Right.Size + 1
            else:
                return 1
        if k < self.Key:
            right_size = 1
            if self.Right != None:
                right_size = self.Right.Size + 1
            return self.Left.find(k) + right_size
        else:
            return self.Right.find(k)

    def find_key_to_remove(self, pos: int):
        this_pos = 1
        if self.Right != None:
            this_pos = self.Right.Size + 1
        if pos == this_pos:
            return self.Key
        if pos < self.Key:
            return self.Right.find_key_to_remove(pos)
        else:
            right_size = 1
            if self.Right != None:
                right_size = self.Right.Size + 1
            return self.Left.find_key_to_remove(pos - right_size)

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
                if self.Left.Key == -1:
                    self.Left = None
        elif k > self.Key:
            if self.Right != None:
                self.Right.remove(k)
                if self.Right.Key == -1:
                    self.Right = None
        else: #  k == p->key
            q = self.Left
            r = self.Right
            if r == None:
                if q == None:
                    self.Key = -1
                    self.Right = None
                    self.Left = None
                    self.Size = -1
                else:
                    self.Key = q.Key
                    self.Right = q.Right
                    self.Left = q.Left
                    self.Size = q.Size
                self.balance()
                return
            min = r.findmin()
            min.Right = r.removemin()
            min.Left = q
            min.balance()
            self.Key = min.Key
            self.Right = min.Right
            self.Left = min.Left
            self.Size = min.Size
            return
        self.balance()
        return

def process_command(arr: list) -> node:
    top_node = None
    result = []
    for elem in arr:
        if elem[0] == 1:
            if top_node == None:
                top_node = node(elem[1])
                result.append(0)
            else:
                top_node.insert(elem[1])
                k = top_node.find(elem[1])
                result.append(k - 1)
        else:
            assert top_node != None
            key = top_node.find_key_to_remove(elem[1] + 1)
            top_node.remove(key)
    return (result, top_node)

def main():
    reader = (list(map(int, line.split(" "))) for line in sys.stdin)
    n, = next(reader)
    arr = list(reader)
   
    assert n == len(arr)

    result, top_node = process_command(arr)    
    
    [print(elem, end = ' ') for elem in result]
    print()

def test():
    print("1 test start")

    result, top_node = process_command([[1, 100], [1, 200], [1, 50], [2, 1], [1, 150]])
    [print(elem, end = ' ') for elem in result]
    print()
    assert result == [0, 0, 2, 1]
    print("1 test end\n")
    print("2 test start")

    result, top_node = process_command([[1, 41], [1, 18467], [2, 0], [1, 26500], [1, 19169], [2, 1], [1, 11478], [1, 29358], [2, 2], [1, 24464], [1, 5705], [2, 0], [1, 23281], [1, 16827], [2, 1]])
    [print(elem, end = ' ') for elem in result]
    print()
    assert result == [0, 0, 0, 1, 1, 0, 2, 3, 2, 3]
    print("2 test end\n")
    

if __name__ == "__main__":
    main()
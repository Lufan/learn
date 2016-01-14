import sys

"""
https://stepic.org/lesson/%D0%91%D1%8B%D1%81%D1%82%D1%80%D0%B0%D1%8F-%D1%81%D0%BE%D1%80%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%BA%D0%B0-%D0%B8-%D0%BF%D0%BE%D1%80%D1%8F%D0%B4%D0%BA%D0%BE%D0%B2%D1%8B%D0%B5-%D1%81%D1%82%D0%B0%D1%82%D0%B8%D1%81%D1%82%D0%B8%D0%BA%D0%B8-12564/step/4?unit=2992
Дан массив целых чисел в диапазоне [0..10^9]. Размер массива кратен 10 и ограничен сверху значением 
2.5 * 10^7 элементов. Все значения массива являются элементами псевдо-рандомной последовательности. 
Необходимо отсортировать элементы массива за минимально время с использованием быстрой сортировки и 
вывести каждый десятый элемент отсортированной последовательности.

Минимальный набор оптимизаций, который необходимо реализовать:

1. Оптимизация выбора опорного элемента.

2. Оптимизация концевой рекурсии.

Sample Input:
3 0 2 1 5 4 21 4 6 5
Sample Output:
21
"""


def partition(array, start_pos, end_pos):
    return (int)((start_pos + end_pos) / 2)


def qsort_helper(array, start_pos, end_pos):
    pivot = partition(array, start_pos, end_pos)
    if start_pos >= end_pos:
        return array
    i = start_pos
    j = end_pos
    while i < j:
        while array[i] < array[pivot]:
            i += 1
        while array[j] > array[pivot]:
            j -= 1
        if i <= j:
            temp = array[i]
            array[i] = array[j]
            array[j] = temp
            j -= 1
            i += 1

    """    
    print("array[pivot] = [{0}] = {1}, array[i] = [{2}] = {3}, array[j] = [{4}] = {5}.".format(pivot, array[pivot], i, array[i], j, array[j]))
    [print("{0}".format(array[i]), end = ' ') for i in range(len(array))]
    print()
    """

    t = i
    if array[i] > array[pivot]:
        t = i - 1

    temp = array[t]
    array[t] = array[pivot]
    array[pivot] = temp

    """    
    [print("{0}".format(array[i]), end = ' ') for i in range(len(array))]
    print()
    """
    if start_pos < j:
        qsort_helper(array, start_pos, j)
    if i < end_pos:
        qsort_helper(array, i, end_pos)
    
    return array

def qsort(arr):
    temp = qsort_helper(arr, 0, len(arr) - 1)
    return temp

def main():
    reader = (list(map(int, line.split(" "))) for line in sys.stdin)
    arr = next(reader)
    assert len(arr) % 10 == 0

    qsort(arr)
    [print("{0} ".format(arr[i]), end = ' ') for i in range(9, len(arr), 10)]
    print()


def test():
    assert qsort([3, 0, 2, 1, 5, 4, 21, 4, 6, 5]) == [0, 1, 2, 3, 4, 4, 5, 5, 6, 21]
    print("**********")
    assert qsort([0]) == [0]
    print("**********")
    assert qsort([0, 1, 2, 3, 4, 5, 6, 7, 8, 9]) == [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    print("**********")
    assert qsort(list(reversed([0, 1, 2, 3, 4, 5, 6, 7, 8, 9]))) == [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    print("**********")
    assert qsort([0, 1]) == [0, 1]
    print("**********")
    assert qsort([1, 0]) == [0, 1]



if __name__ == "__main__":
    test()
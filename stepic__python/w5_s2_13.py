import sys
"""
Реализуйте структуру данных типа “множество строк” на основе динамической хеш-таблицы с открытой адресацией. 
Хранимые строки непустые и состоят из строчных латинских букв. Начальный размер таблицы должен быть равным 8-ми. 
Перехеширование выполняйте в случае, когда коэффициент заполнения таблицы достигает 3/4.
Структура данных должна поддерживать операции добавления строки в множество, удаления строки из 
множества и проверки принадлежности данной строки множеству.
Для разрешения коллизий используйте квадратичное пробирование. i-ая проба

g(k,i)=g(k,i−1)+i(mod m), где m - степень двойки. 

Каждая строка входных данных задает одну операцию над множеством. Запись операции состоит из 
типа операции и следующей за ним через пробел строки, над которой проводится операция.
Тип операции  – один из трех символов:
   +  означает добавление данной строки в множество; 
   -  означает удаление  строки из множества;  
   ?  означает проверку принадлежности данной строки множеству.

При добавлении элемента в множество НЕ ГАРАНТИРУЕТСЯ, что он отсутствует в этом множестве. При 
удалении элемента из множества НЕ ГАРАНТИРУЕТСЯ, что он присутствует в этом множестве. 
Программа должна вывести для каждой операции одну из двух строк OK или FAIL, в зависимости от того, 
встречается ли данное слово в нашем множестве. 

Sample Input:
+ hello
+ bye
? bye
+ bye
- bye
? bye
? hello
Sample Output:
OK
OK
OK
FAIL
OK
FAIL
OK
"""
class hash_sqr:
    """Структура данных типа “множество строк” на основе динамической хеш-таблицы с открытой адресацией"""
    # метка для удаленного элемента
    __deleted_str = "__deleted_str"
    # когда коэффициент заполнения таблицы достигает 3/4
    # требуется выполнить процесс перехешироания
    __max_a = 3/4
    # количество элементов в таблице
    __N = 0
    # текущий коэффициент заполнения таблицы
    def __get_a(self) -> float:
        return self.__N / self.__m

    # коэффициенты функции хэширования
    def __a(self) -> int:
        return self.__m * 2 - 1 
    # Начальный размер таблицы должен быть равным 8-ми.
    __m = 8
    # Размер является степенями двойки
    def __next_m(self) -> None:
        self.__m *= 2

    def __init__(self):
        self.__table = [None for _ in range(self.__m)]

    def append(self, element: str) -> bool:
        """Добавляет элемент в таблицу и возвращаем True, если элемент уже есть в таблице то новый не добавляется и возвращается False"""
        position = self.__get_free_position(element)
        if position < 0:
            return False
        self.__table[position] = element
        # увеличиваем счетчик элементов в таблице
        self.__N += 1
        # выполняем перехэширование при заполненности таблицы
        if self.__get_a() >= self.__max_a:
            self.__rehash()
            pass
        return True

    def delete(self, element: str) -> bool:
        """Удаляем элемент из таблицы и возвращаем True, если элемента в таблице нет то возвращается False"""
        position = self.__get_position(element)
        if position < 0:
            return False
        self.__table[position] = self.__deleted_str
        # уменьшаем счетчик элементов в таблице
        self.__N -= 1
        return True

    def contain(self, element: str) -> bool:
        pos = self.__get_position(element)
        return not pos == -1

    def __rehash(self) -> None:
        # увеличиваем диапазон ключей
        temp = []
        for elem in self.__table:
            if elem != None and elem != self.__deleted_str:
                temp.append(elem)
        self.__next_m()
        self.__table = [None for _ in range(self.__m)]
        for elem in temp:
            self.append(elem)
            self.__N -= 1
        return None

    def __get_position(self, element: str) -> int:
        """Возвращает позицию (хэш) элемента или -1 если элемент не найден"""
        a = self.__a()
        m = self.__m
        hash = self.__hash(element, a, m)
        i = 0
        while i < self.__m and hash < self.__m:
            if (self.__table[hash] == element):
                return hash
            else:
                # Для разрешения коллизий используется квадратичное пробирование. 
                # i-ая проба: g(k,i)=g(k,i−1)+i(mod m), где m - степень двойки.
                hash = hash + i % self.__m
            i += 1
        # если не нашли свободное то место возвращаем -1
        return -1

    def __get_free_position(self, element: str) -> int:
        """Возвращает позицию (хэш) для вставки элемента или -1 если элемент уже существует"""
        a = self.__a()
        m = self.__m
        hash = self.__hash(element, a, m)
        i = 0
        while i < self.__m:
            if (self.__table[hash] == element):
                return -1
            if (self.__table[hash] == None) or (self.__table[hash] == self.__deleted_str):
                return hash
            else:
                # Для разрешения коллизий используется квадратичное пробирование. 
                # i-ая проба: g(k,i)=g(k,i−1)+i(mod m), где m - степень двойки.
                hash = hash + i % self.__m
            i += 1
        # если не нашли свободное то место возвращаем ошибку
        assert False
        return -1

    def __hash(self, elem: str, a: int, m: int) -> int:
        """Расчет хэша строки методом Горнера"""
        result = ord(elem[0]) * a
        for i in range(1, len(elem)):
            result = (result * a + ord(elem[i])) % m
        return int(result)

def process_commands(arr: list) -> list:
    if not isinstance(arr, list):
        raise TypeError
    table = hash_sqr()
    result_arr = []
    for elems in arr:
        command = elems[0]
        argument = elems[1]
        result = {
            '+' : lambda x: table.append(x),
            '-' : lambda x: table.delete(x),
            '?' : lambda x: table.contain(x)
            }[command](argument)
        if result:
            result_arr.append('OK')
        else:
            result_arr.append('FAIL')
    return result_arr

def strip(elem: str = "") -> str:
    """Удаление в конце строки символа \n"""
    if not isinstance(elem, str):
        raise TypeError("strip(element) -> element must be a type str")
    return elem.strip("\n")

def main():
    reader = (list(map(strip, line.split(" "))) for line in sys.stdin)
    arr = list(reader)
    
    result = process_commands(arr)
    [print("{0}".format(elem), end = '\n') for elem in result]
    print()

def test():
    print("1 test start")
    assert process_commands([]) == []
    print("1 test end\n2 test start")
    assert process_commands([['+', 'hello'], ['+', 'bye'], ['+', 'hello2'], ['+', 'hello3'], ['+', 'hello4'], ['+', 'hello5'], ['+', 'hello6'], ['+', 'hello7']]) == ['OK', 'OK', 'OK', 'OK', 'OK', 'OK', 'OK', 'OK']
    print("2 test end\n3 test start")
    assert process_commands([['+', 'hello'], ['+', 'bye'], ['+', 'hello2'], ['+', 'hello3'], ['+', 'hello'], ['+', 'bye'], ['+', 'hello2'], ['+', 'hello7']]) == ['OK', 'OK', 'OK', 'OK', 'FAIL', 'FAIL', 'FAIL', 'OK']
    print("3 test end\n4 test start")
    assert process_commands([['+', 'hello'], ['+', 'hello'], ['?', 'hello'], ['?', 'hello3']]) == ['OK', 'FAIL', 'OK', 'FAIL']
    print("4 test end\n5 test start")
    assert process_commands([['?', 'hello']]) == ['FAIL']
    print("5 test end\n6 test start")
    assert process_commands([['+', 'hello'], ['+', 'bye'], ['?', 'bye'], ['+', 'bye'], ['-', 'bye'], ['?', 'bye'], ['?', 'hello']]) == ['OK', 'OK', 'OK', 'FAIL', 'OK', 'FAIL', 'OK']
    print("6 test end")


if __name__ == "__main__":
    main()
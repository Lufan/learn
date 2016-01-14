/*
Напишите программу, читающую из System.in текст в кодировке UTF-8, подсчитывающую в нем частоту появления слов, и в конце выводящую 10 наиболее часто встречающихся слов.

Словом будем считать любую непрерывную последовательность символов, состоящую только из букв и цифр. Например, в строке "Мама мыла раму 33 раза!" ровно пять слов: "Мама", "мыла", "раму", "33" и "раза".

Подсчет слов должен выполняться без учета регистра, т.е. "МАМА", "мама" и "Мама" — это одно и то же слово. Выводите слова в нижнем регистре.

Если в тексте меньше 10 уникальных слов, то выводите сколько есть.

Если в тексте некоторые слова имеют одинаковую частоту, т.е. их нельзя однозначно упорядочить только по частоте, то дополнительно упорядочите слова с одинаковой частотой в лексикографическом порядке.

Задача имеет красивое решение через стримы без циклов и условных операторов. Попробуйте придумать его.

Sample Input 1:
Мама мыла-мыла-мыла раму!
Sample Output 1:
мыла
мама
раму

Sample Input 2:
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed sodales consectetur purus at faucibus. Donec mi quam, tempor vel ipsum non, faucibus suscipit massa. Morbi lacinia velit blandit tincidunt efficitur. Vestibulum eget metus imperdiet sapien laoreet faucibus. Nunc eget vehicula mauris, ac auctor lorem. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer vel odio nec mi tempor dignissim.
Sample Output 2:
consectetur
faucibus
ipsum
lorem
adipiscing
amet
dolor
eget
elit
mi
*/

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;
import java.util.HashMap;
import java.util.stream.Stream;

public class Main {
    public static void main(String[] args) {
	// write your code here
    HashMap<String, Integer> result = new HashMap<>();
    // Создаем отображение каждого слова на его количество
    (new BufferedReader(new InputStreamReader(System.in, StandardCharsets.UTF_8)))
            .lines()
            .flatMap(l -> Stream.of(l.split("[\\p{Punct}\\s]+")))
            .map(w -> w.toLowerCase())
            .forEach(w -> {
                if(result.containsKey(w)) result.put(w, result.get(w) + 1);
                else result.put(w, 1);
            });
    // Сортируем отображение по количеству слов в обратном порядке, по словам в лексиграфическом
    // и выводим первых 10 элементов в stdout
    result.entrySet()
            .stream()
            .sorted((e1, e2) -> {
                if(e1.getValue() == e2.getValue()) return e1.getKey().compareTo(e2.getKey());
                else return e2.getValue().compareTo(e1.getValue());})
            .limit(10)
            .forEach(e -> System.out.println(e.getKey()));
    }
}
/*
Напишите программу, которая прочитает из System.in последовательность целых чисел, разделенных пробелами, затем удалит из них все числа, стоящие на четных позициях, и затем выведет получившуюся последовательность в обратном порядке в System.out.

Все числа влезают в int. Позиции чисел в последовательности нумеруются с нуля.

В этом задании надо написать программу целиком, включая import'ы, декларацию класса Main и метода main.

Sample Input:
1 2 3 4 5 6 7
Sample Output:
6 4 2
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;

public class Main {

    public static void main(String[] args) {
        // write your code here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try {
            String[] line = br.readLine().split(" ");
            int i = line.length;
            LinkedList<String> buff = new LinkedList<>();
            for (int j = 1; j < i; ++j) {
                if ((j & 1) != 0) {
                    buff.addFirst(line[j]);
                }
            }
            buff.forEach(e -> System.out.print(e + " "));
        } catch (IOException e) {

        } catch (NullPointerException e) {

        }   
    }
}

/*
Напишите программу, читающую текст из System.in и выводящую в System.out сумму всех встреченных в тексте вещественных чисел с точностью до шестого знака после запятой. Числом считается последовательность символов, отделенная от окружающего текста пробелами или переводами строк и успешно разбираемая методом Double.parseDouble.

На этот раз вам надо написать программу полностью, т.е. объявить класс (с именем Main — таково ограничение проверяющей системы), метод main, прописать все import'ы.

Sample Input 1:
1 2 3
Sample Output 1:
6.000000

Sample Input 2:
a1 b2 c3
Sample Output 2:
0.000000

Sample Input 3:
-1e3
18 .111 11bbb
Sample Output 3:
-981.889000
*/

import java.io.IOException;
import java.io.Reader;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
	// write your code here
        Reader r = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int c;
        while ((c = r.read()) != -1){
            sb.append((char)c);
        }
        double sum = 0.0;
        StringTokenizer st = new StringTokenizer(sb.toString());
        while (st.hasMoreTokens()) {
            String token = st.nextToken();
            try {
                double num = Double.parseDouble(token);
                sum += num;
            } catch (NumberFormatException e2){
                // Skip token
            }
        }
        System.out.printf("%.6f", sum);
        System.out.flush();
    }
}
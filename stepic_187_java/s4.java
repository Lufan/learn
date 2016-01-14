/*
Напишите класс AsciiCharSequence, реализующий компактное хранение последовательности 
ASCII-символов (их коды влезают в один байт) в массиве байт. По сравнению с классом 
String, хранящим каждый символ как char, AsciiCharSequence будет занимать в два раза 
меньше памяти.

Класс AsciiCharSequence должен:

реализовывать интерфейс java.lang.CharSequence;
иметь конструктор, принимающий массив байт;
определять методы length(), charAt(), subSequence() и toString()
Сигнатуры методов и ожидания по их поведению смотрите в описании интерфейса 
java.lang.CharSequence (JavaDoc или исходники).

В данном задании методам charAt() и subSequence() всегда будут подаваться корректные 
входные параметры, поэтому их проверкой и обработкой ошибок заниматься не нужно. 
Тем более мы еще не проходили исключения.

P.S. В Java 9 ожидается подобная оптимизация в самом классе String: 
http://openjdk.java.net/jeps/254
*/

public class AsciiCharSequence implements CharSequence {
    private byte[] content;

    public AsciiCharSequence(byte[] content) {
        this.content = content;
    }

    @Override
    public int length() {
        return content.length;
    }

    @Override
    public char charAt(int index) {
        return (char)content[index];
    }

    @Override
    public CharSequence subSequence(int start, int end) {
        byte[] result = new byte[end-start];
        for(int i = start; i < end; i++ ){
            result[i-start] = content[i];
        }
        return new AsciiCharSequence(result);
    }

    @Override
    public String toString() {
        StringBuilder result = new StringBuilder(content.length);
        for(int i = 0; i < content.length; i++ ){
            result.append((char)content[i]);
        }
        return result.toString();
    }
}
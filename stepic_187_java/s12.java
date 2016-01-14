/*
Реализуйте generic-класс Pair, похожий на Optional, но содержащий пару элементов разных типов и не запрещающий элементам принимать значение null.

Реализуйте методы getFirst(), getSecond(), equals() и hashCode(), а также статический фабричный метод of(). Конструктор должен быть закрытым (private).

С корректно реализованным классом Pair должен компилироваться и успешно работать следующий код:

Pair<Integer, String> pair = Pair.of(1, "hello");
Integer i = pair.getFirst(); // 1
String s = pair.getSecond(); // "hello"

Pair<Integer, String> pair2 = Pair.of(1, "hello");
boolean mustBeTrue = pair.equals(pair2); // true!
boolean mustAlsoBeTrue = pair.hashCode() == pair2.hashCode(); // true!


Пожалуйста, не меняйте модификатор доступа класса Pair. Для корректной проверки класс должен иметь пакетную видимость.
*/

class Pair <X, Y>{
    private Pair(X x, Y y){
        firstValue = x;
        secondValue = y;
    }
    private X firstValue;
    private Y secondValue;

    public static <X, Y> Pair<X, Y> of(X x, Y y) {
        return new Pair(x, y);
    }
    public X getFirst() {
        return firstValue;
    }
    public Y getSecond() {
        return secondValue;
    }
    @Override
    public boolean equals(Object other){
        if (this == other) {
            return true;
        }
        if (Pair.class.isInstance(other)) {
            return Objects.equals(firstValue, ((Pair<?,?>)other).firstValue) &&
                    Objects.equals(secondValue, ((Pair<?,?>)other).secondValue);
        }
        return false;
    }
    @Override
    public int hashCode() {
        return Objects.hashCode(this.getFirst()) ^ Objects.hashCode(this.getSecond());
    }
}
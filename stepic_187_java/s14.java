/*
Напишите метод, находящий в стриме минимальный и максимальный элементы в соответствии порядком, заданным Comparator'ом.

Найденные минимальный и максимальный элементы передайте в minMaxConsumer следующим образом:

minMaxConsumer.accept(min, max);
Если стрим не содержит элементов, то вызовите
minMaxConsumer.accept(null, null);
*/

public static <T> void findMinMax(
        Stream<? extends T> stream,
        Comparator<? super T> order,
        BiConsumer<? super T, ? super T> minMaxConsumer) {

    // your implementation here
    final Object[] max = new Object[1];
    final Object[] min = new Object[1];
    max[0] = null;
    min[0] = null;
    stream.forEach(e -> {
        if (max[0] == null) max[0] = e;
        if (min[0] == null) min[0] = e;
        int t = order.compare((T)max[0], e);
        if (t < 0) max[0] = e;
        t = order.compare((T)min[0], e);
        if (t > 0) min[0] = e;
    });
    minMaxConsumer.accept(min[0] != null?(T)min[0]:null, max[0] != null?(T)max[0]:null);
}
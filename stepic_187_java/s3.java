/*
Дан класс ComplexNumber. Переопределите в нем методы equals() и hashCode() так, 
чтобы equals() сравнивал экземпляры ComplexNumber по содержимому полей re и im, 
а hashCode() был бы согласованным с реализацией equals().

Реализация hashCode(), возвращающая константу, засчитана не будет

Пример

ComplexNumber a = new ComplexNumber(1, 1);
ComplexNumber b = new ComplexNumber(1, 1);
// a.equals(b) must return true
// a.hashCode() must be equal to b.hashCode()

P.S. Если задача никак не решается, можно позвать на помощь среду разработки, 
которая умеет сама генерировать equals() и hashCode(). Если вы воспользовались 
помощью IDE, то разберитесь, что было сгенерировано и почему оно выглядит 
именно так. Когда вас на собеседовании попросят на бумажке реализовать equals() 
и hashCode() для какого-нибудь простого класса, то среда разработки помочь не сможет.
*/

public final class ComplexNumber {
    private final double re;
    private final double im;

    public ComplexNumber(double re, double im) {
        this.re = re;
        this.im = im;
    }

    public double getRe() {
        return re;
    }

    public double getIm() {
        return im;
    }
    
    @Override
    public boolean equals(Object other){
        if (this == other) {
            return true;
        }
        if (other instanceof ComplexNumber){
            ComplexNumber temp = (ComplexNumber)other;
            return this.re == temp.getRe() && this.im == temp.getIm();
        }
        return false;
    }

    @Override
    public int hashCode(){
       return (int) ((re - 5) * (im + 7));
    } 
    
}
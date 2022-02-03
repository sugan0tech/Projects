import java.util.*;

class vehicle {
    int count;

    public void print() {

        System.out.println(count);
    }

}

class car extends vehicle {
    int number;

    public car(int a, int c) {
        number = a;
        count = c;
    }

    public void print() {
        System.out.println(count);
        System.out.println(number);
    }

}

public class TestClass {
    public static void main(String args[]) {
        car bus = new car(4, 5);
        bus.print();

    }

}

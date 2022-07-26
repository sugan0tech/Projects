import java.util.*;

// loose coupling 
final class A {
    private int volume;

    A(int a, int b, int c) {
        this.volume = a * b * c;
    }

    int getVolume() {
        return this.volume;
    };
}

class B {
    void print() {
        System.out.println(new A(1, 2, 3).getVolume());
    }
}

public class LoseCouple {
    public static void main(String args[]) {
        new B().print();

    }
}
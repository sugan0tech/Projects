import java.util.*;

// tight coupling 
class A {
    int volume;

    A(int a, int b, int c) {
        this.volume = a * b * c;
    }
}

class B {
    void print() {
        System.out.println(new A(1, 2, 3).volume);
    }
}

public class Coupling {
    public static void main(String args[]) {
        new B().print();

    }
}
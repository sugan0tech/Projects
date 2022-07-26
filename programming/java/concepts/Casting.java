import java.util.*;

class Parent {
    void print() {
        System.out.println("Hi from parent");
    }

}

class Child extends Parent {
    @Override
    void print() {
        System.out.println("Hi from child");
    }

}

public class Casting {
    public static void main(String args[]) {
        Parent c = (Parent) new Child(); // UpCasting
        c.print();
        Child c1 = (Child) c; // DownCasting
        c1.print();

    }

}

abstract class Animal {
    public abstract void sounds();

}

class cat extends Animal {
    public void sounds() {
        System.out.println("meao");
    }
}

public class Second {
    protected int data;

    public Second() {
        data = 0;
    }

    public Second(int x) {
        data = x;
    }

    public static void print() {
        System.out.println("from the second.java files ig");
    }

    public static void main(String[] args) {

    }
}

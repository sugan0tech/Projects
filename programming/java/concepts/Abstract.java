interface Test {
    public void test();
}

class Tst implements Test {
    public void test() {

        System.out.println("test");
    };
}

interface Parent1 {
    public void print();
}

interface Parent2 {
    public void print2();
}

class child implements Parent1, Parent2 {

};

public class Abstract {
    public static void main(String[] args) {
        Tst obj = new Tst();
        obj.test();
    }

}

public class Finalize {
    public static void main(String args[]) {
        Finalize ob = new Finalize();
        ob.test();
        ob = null;
        System.gc();
        System.out.println("The End");
    }

    void test() {
        System.out.println("test");
    }

    @Override
    protected void finalize() {
        System.out.println("Finally it is going to die");
    }

}

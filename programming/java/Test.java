public class Test {

    public static void fun() {
        System.out.println("fun");

    };

    public void hi() {
        System.out.println(":thinking:");
    };

    public static void main(String[] args) {
        byte[] arr = { 1, 2, 3, 4, 5, 6, 7 };

        for (byte i : arr) {
            System.out.println(i);
        }
        fun();
        new Test().hi();
    };

}
import java.util.*;

public class Exception {
    public static void main(String args[]) {
        System.out.println("hi there");
        try {
            int a = 1 / 0;
        } catch (ArithmeticException e) {
            System.out.println(e);
        } finally {
            System.out.println("finally");
        }

    }
}
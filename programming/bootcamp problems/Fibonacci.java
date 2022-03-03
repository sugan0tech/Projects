import java.util.*;

public class Fibonacci {
    public static int fib(int n) {
        if (n <= 1)
            return 1;
        return fib(n - 1) + fib(n - 2);
    }

    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int a = 0, b = 1, c = 0;
        while (n != 0) {
            c = a + b;
            a = b;
            b = c;
            n--;
        }
        System.out.println(c);
        System.out.println(fib(8));
        scan.close();

    }
}
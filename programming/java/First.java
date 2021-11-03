import java.util.*;

public class First {
    public static void main(String[] args) {
        System.out.println("Hello world");
        System.out.println("\nres " + tst(4, 3));
        Scanner s = new Scanner(System.in);
        int tmp = s.nextInt();
        int tmp2 = s.nextInt();
        System.out.println(" " + tmp + "  " + tmp2);
        s.close();
    }

    static int tst(int x, int y) {
        int tmp = 0;
        for (int i = 0; i < 10; i++) {

            tmp += x + y + i;
        }
        return tmp;
    }
}
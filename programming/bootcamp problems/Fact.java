import java.util.*;

public class Fact {
    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int val = 1;
        for (int i = 1; i <= n; i++) {
            val *= i;
        }
        System.out.println(val);

    }

}

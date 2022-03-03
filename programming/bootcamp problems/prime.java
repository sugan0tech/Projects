import java.util.*;

public class prime {
    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        boolean boo = true;
        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                boo = false;
            }
        }
        if (boo)
            System.out.println("prime number");
        else
            System.out.println("Not prime number");
        scan.close();

    }

}

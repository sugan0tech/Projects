import java.util.*;

public class Perfect {

    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        int count = 0;
        int n = scan.nextInt();
        for (int i = 1; i < n; i++) {
            if (n % i == 0)
                count += i;

        }
        if (count == n)
            System.out.println("perfect number");
        else
            System.out.println("not a perfect number");

        scan.close();
    }

}

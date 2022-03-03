import java.util.*;

public class Amstrong {
    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int count = 0, tmp = n, tmp2;
        while (tmp != 0) {

            tmp2 = tmp % 10;
            count += tmp2 * tmp2 * tmp2;
            tmp = tmp / 10;
        }
        if (count == n)

            System.out.println("It's an amstrong number");
        else
            System.out.println("It's not an amstrong number");

    }

}

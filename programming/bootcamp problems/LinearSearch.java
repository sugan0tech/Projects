import java.util.*;

public class LinearSearch {
    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        int n = scan.nextInt();
        boolean bool = false;
        for (int i : arr) {
            if (n == i) {
                System.out.println("found it");
                bool = true;
            }
        }
        if (!bool)
            System.out.println("not found");

    }

}

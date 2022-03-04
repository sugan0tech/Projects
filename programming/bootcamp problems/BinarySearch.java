import java.util.*;

public class BinarySearch {
    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        int e = scan.nextInt();
        int l = 0, r = arr.length - 1, m;
        while (l <= r) {
            m = l + (r - l) / 2;

            if (arr[m] == e) {
                System.out.println("found it ");
                break;
            }
            if (arr[m] < e)
                l = m + 1;
            else
                r = m - 1;
        }
    }

}

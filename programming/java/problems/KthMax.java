import java.util.*;
import java.util.Collections;

public class KthMax {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        ArrayList<Integer> arr = new ArrayList<Integer>();
        arr.addAll(Arrays.asList(3, 2, 8, 7, 1, 4, 9, 6, 5));
        Collections.sort(arr);
        int k = scan.nextInt(), min = 0, max = 0;

        for (int i = 0, j = arr.size() - 1; i < k; i++, j--) {

            min = arr.get(i);
            max = arr.get(j);
        }
        System.out.println("Kth min :" + min + " Kth max :" + max);

    }
}
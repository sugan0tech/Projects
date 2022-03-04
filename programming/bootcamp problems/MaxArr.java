import java.util.*;

public class MaxArr {
    public static void main(String args[]) {
        int arr[] = { 1, 2, 3, 4, 6, 8, 7, 9 };
        int max = arr[0];
        for (int i : arr) {
            if (i > max)
                max = i;
        }
        System.out.println(max);
    }
}

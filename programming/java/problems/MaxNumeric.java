import java.util.ArrayList;
import java.util.Arrays;

public class MaxNumeric {
    public static void main(String[] args) {

        // classic approach
        System.out.print("\nClassic approach \n");
        int[] arr = { 1, 2, 3, 4, 5, 6, 7 };
        int n = 7, min = arr[0], max = min;
        for (int i = 0; i < n; i++) {
            if (min < arr[i])
                min = arr[i];
            if (max > arr[i])
                max = arr[i];

        }
        System.out.print("max :" + max + " min :" + min + "\n");

        System.out.print("\nClass approach \n");
        // java class ic apporaoch
        ArrayList<Integer> ar = new ArrayList<Integer>();
        ar.addAll(Arrays.asList(1, 2, 3, 4, 5, 6, 7));
        min = ar.get(0);
        max = min;
        for (int i : ar) {
            if (min < i)
                min = i;
            if (max > i)
                max = i;

        }
        System.out.print("max :" + max + " min :" + min + "\n");

    }

}

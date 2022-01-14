
import java.util.ArrayList;
import java.util.Arrays;

public class ArrayReverse {
    public static void main(String[] args) {

        // classic approach
        System.out.print("\nClassic approach \n");
        int[] arr = { 1, 2, 3, 4, 5, 6, 7 };
        int n = 7, tmp;
        for (int i = 0, j = n - 1; i < n / 2; i++, j--) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }

        System.out.print("\nClass approach \n");
        // java class ic apporaoch
        ArrayList<Integer> ar = new ArrayList<Integer>();
        ar.addAll(Arrays.asList(1, 2, 3, 4, 5, 6, 7));
        for (int i = 0, j = ar.size() - 1; i < ar.size() / 2; i++, j--) {
            tmp = ar.get(i);
            ar.set(i, ar.get(j));
            ar.set(j, tmp);
        }
        System.out.println(ar);

    }

}
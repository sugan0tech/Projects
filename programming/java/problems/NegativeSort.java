import java.util.*;

public class NegativeSort {
    public static void main(String[] args) {
        ArrayList<Integer> arr = new ArrayList<Integer>();
        arr.addAll(Arrays.asList(-1, -3, 1, 2, -4, 6));
        int ptr = 0, tmp;
        for (int i = 0; i < arr.size(); i++) {
            if (arr.get(i) < 0) {
                if (i != ptr)
                    Collections.swap(arr, i, ptr);
                ptr++;
            }
        }
        System.out.println(arr);
    }
}
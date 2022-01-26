import java.util.*;

public class Cyclic {
    public static void main(String args[]) {
        int[] arr = { 1, 2, 3, 4, 5, 6, 7 };
        int tmp = arr[6], tmp2;
        for (int i = 0; i < 7; i++) {
            tmp2 = arr[i];
            arr[i] = tmp;
            tmp = tmp2;
        }
        for (int i : arr) {
            System.out.print(i);
        }
        System.out.println();

    }

}

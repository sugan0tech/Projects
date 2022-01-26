import java.util.ArrayList;
import java.util.Arrays;

public class UnionIntersect {
    public static void main(String[] args) {
        int arr1[] = { 1, 2, 4, 5, 6, 8, 9 };
        int arr2[] = { 3, 5, 7 };
        int n = 7, m = 3, lcb = 0;
        ArrayList<Integer> arr = new ArrayList<Integer>();
        for (int i = 0, j = 0; (j < m) && (i < n);) {
            if (arr1[i] < arr2[j]) {
                arr.add(arr1[i]);
                i++;
            } else if (arr1[i] > arr2[j]) {
                arr.add(arr2[j]);
                j++;
            } else if (arr1[i] == arr2[j]) {
                arr.add(arr2[j]);
                j++;
                i++;
            }
            lcb = i;
        }
        System.out.println("Union : " + arr);
        System.out.print("\nIntersection : [");

        for (int i = lcb; i < n; i++) {
            System.out.print(" " + arr1[i]);
        }
        System.out.print(" ]\n ");

    }

}

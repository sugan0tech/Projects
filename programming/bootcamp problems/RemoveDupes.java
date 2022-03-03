import java.util.*;

public class RemoveDupes {
    public static void main(String args[]) {
        int arr[] = { 1, 2, 3, 3, 4, 5, 6 };
        Set<Integer> set = new HashSet<>();
        for (int i : arr) {
            set.add(i);
        }
        System.out.println(set);
    }

}

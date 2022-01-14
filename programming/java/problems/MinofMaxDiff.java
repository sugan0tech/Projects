import java.util.*;

public class MinofMaxDiff {
    public static void main(String[] args) {
        ArrayList<Integer> arr = new ArrayList<Integer>();
        arr.addAll(Arrays.asList(3, 20, 12, 9, 16));
        Collections.sort(arr);
        int k = 3;
        int ans = arr.get(arr.size() - 1) - arr.get(0); // max possible value
        int small = arr.get(0) + k;
        int large = arr.get(arr.size() - 1) - k;
        int min, max;

        for (int i = 0; i < arr.size() - 1; i++) {
            min = Math.min(small, arr.get(i + 1) - k);
            max = Math.max(large, arr.get(i) + k);
            if (min < 0)
                continue;

            ans = Math.min(ans, max - min);
        }
        System.out.println(ans);
    }

}

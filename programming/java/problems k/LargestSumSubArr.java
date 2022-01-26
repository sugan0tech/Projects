import java.util.*;

public class LargestSumSubArr {

    public static int max(int a, int b) {
        if (a > b)
            return a;
        return b;

    }

    public static void main(String[] args) {
        ArrayList<Integer> arr = new ArrayList<Integer>();
        arr.addAll(Arrays.asList(1, 2, 3, -2, 5));
        System.out.println(arr);
        int sum = arr.get(0), max = sum, e;
        for (int i = 1; i < arr.size(); i++) {
            e = arr.get(i);
            sum = max(e, e + sum);
            max = max(max, sum);

        }
        System.out.println(max);

    }

}
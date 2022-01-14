import java.util.*;

public class ZeroOneTwo {
    public static void main(String[] args) {
        ArrayList<Integer> arr = new ArrayList<Integer>();
        arr.addAll(Arrays.asList(0, 1, 2, 0, 1, 2, 1, 0));
        System.out.println(arr);
        int low = 0, high = arr.size() - 1, mid = 0, tmp;
        while (mid <= high) {
            switch (arr.get(mid)) {
                case 0:
                    tmp = arr.get(low);
                    arr.set(low, arr.get(mid));
                    arr.set(mid, tmp);
                    low++;
                    mid++;
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    tmp = arr.get(mid);
                    arr.set(mid, arr.get(high));
                    arr.set(high, tmp);
                    high--;
                    mid++;
                    break;
            }

        }
        System.out.println(arr);
        ;
    }

}

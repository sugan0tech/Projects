import java.util.*;

public class Arr {
    public static void main(String[] args) {
        List<Integer> tst = new LinkedList<Integer>();
        tst.add(3);
        tst.add(1);
        tst.add(2);
        tst.add(5);
        tst.add(3);
        repeatedNumber(tst);

    }

    public static void repeatedNumber(final List<Integer> A) {
        int size = A.size();
        System.out.println(size);
        int[] arr = new int[size];
        System.out.println(arr);
        ArrayList<Integer> res = new ArrayList<Integer>();
        int i;

        for (i = 0; i < size; i++) {
            arr[i] = 0;
        }

        for (int j : A) {
            arr[j] += 1;
            System.out.println(arr[j]);
        }

        for (i = 0; i < size; i++) {
            if (arr[i] > 1)
                res.add(arr[i]);
            if (arr[i] == 0)
                res.add(arr[i]);
            break;
        }

        System.out.println(res);

    }
}
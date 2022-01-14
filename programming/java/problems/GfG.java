import java.util.*;

public class GfG {
    public static boolean check(int n) {
        int tmp = n % 10;
        int chekc = n % 10;
        while (n > 0) {
            n = Math.floorDiv(n, 10);
            tmp = n % 10;
            System.out.println(tmp);
            System.out.println(chekc);
            if (chekc <= tmp) {
                return false;
            }
            chekc = tmp;
        }
        return true;
    }

    public static void main(String[] args) {

        int N = 2;
        System.out.println(check(10));
        ArrayList<Integer> arr = new ArrayList<Integer>();
        if (N == 1) {
            for (int i = 0; i <= 9; i++) {
                arr.add(i);
            }
        } else {
            int start = (int) Math.pow(10, (N - 1));
            for (int i = start; i < start * 10; i++) {
                if (check(i) == true) {
                    arr.add(i);
                }
            }
        }
        System.out.println(arr);

    }
}
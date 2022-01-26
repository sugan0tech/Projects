import java.util.*;

public class ZerotoFive {
    static int convertfive(int num) {
        int tmp;
        int count = 1;
        if (num % 10 == 0) {
            num += 5;
        }
        while ((num / (Math.pow(10, count))) > 1) {
            tmp = num / ((int) Math.pow(10, count));
            tmp = tmp % 10;
            System.out.println(num + " " + tmp + " " + count);
            if (tmp == 0) {
                num += 5 * ((int) Math.pow(10, count));
            }
            count++;
        }
        return num;
    }

    public static void main(String args[]) {
        System.out.println(convertfive(1004));

    }

}

import java.util.*;

public class Ds {

    public static void main(String[] args) {
        int n = 10;
        lable: for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                if (i * j > 2) {
                    break lable;
                } else {
                    System.out.println(i);
                }
            }
        }
    }
}
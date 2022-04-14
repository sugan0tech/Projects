import java.util.*;

public class StrBuff {
    public static void main(String[] args) {
        long startTime = System.currentTimeMillis();
        StringBuffer sb = new StringBuffer("Java");
        for (int i = 0; i < 100000; i++) {
            sb.append("Tpoint");
        }
        System.out.println("Time taken by StringBuffer: " + (System.currentTimeMillis() - startTime) + "ms");
        startTime = System.currentTimeMillis();
        StringBuilder sb2 = new StringBuilder("Java");
        for (int i = 0; i < 100000; i++) {
            sb2.append("Tpoint");
        }
        System.out.println("Time taken by StringBuilder: " + (System.currentTimeMillis() - startTime) + "ms");
        startTime = System.currentTimeMillis();
        String sb3 = new String("Java");
        for (int i = 0; i < 100000; i++) {
            sb3 = sb3 + "Tpoint";
        }
        System.out.println("Time taken by String: " + (System.currentTimeMillis() - startTime) + "ms");

    }
}
import java.util.*;

public class Vowels {
    public static void main(String args[]) {
        String s = "sugavanesh";
        String v = "aeiou";
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (v.contains(String.valueOf(s.charAt(i))))
                count++;
        }
        System.out.println(count);
    }
}
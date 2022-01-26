import java.security.KeyStore.Entry;
import java.util.*;

public class RomanInt {
    public static void main(String args[]) {
        HashMap<Character, Integer> map = new HashMap<Character, Integer>();
        map.put('I', 1);
        map.put('V', 5);
        map.put('X', 10);
        map.put('L', 50);
        map.put('C', 100);
        map.put('D', 500);
        map.put('M', 1000);
        String str = "III";
        int c = 0, b = 0, n;
        for (int i = str.length() - 1; i >= 0; i--) {
            n = map.get(str.charAt(i));
            if (c <= n) {
                c = n;
                b += n;
            } else {
                c = n;
                b -= n;
            }

        }
        System.out.println(b);
    }

}

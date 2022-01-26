import java.util.*;

public class Reverse {
    public static void main(String[] args) {
        String str = "pqr.mno", rev = "";
        char ch;
        System.out.println(str.charAt(1));
        System.out.println(str.codePointAt(0));
        System.out.println(str.codePointBefore(1));
        System.out.println(str.concat("how are you uyoi"));
        for (int i = 0; i < str.length(); i++) {

            ch = str.charAt(i);
            rev = ch + rev;
        }
        System.out.println(rev);
        String n = "", word = "";
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == ".".charAt(0)) {
                n = "." + word + n;
                word = "";
            }
            if (str.charAt(i) != ".".charAt(0))
                word = word + str.charAt(i);
        }
        n = word + n;
        System.out.println(str);
        System.out.println(n);

    }
}
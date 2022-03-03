import java.util.*;

public class Palindrome {
    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        String str = scan.nextLine();
        boolean boo = true;
        for (int i = 0; i < str.length() / 2; i++) {
            if (str.charAt(i) != str.charAt(str.length() - 1 - i)) {
                boo = false;
            }
        }
        if (boo)
            System.out.println("it's an palindrome");
        else
            System.out.println("not an palindrome");

    }

}

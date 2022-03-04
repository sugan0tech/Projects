import java.util.*;

public class RepeatedChar {
    public static void main(String args[]) {

        Scanner scan = new Scanner(System.in);
        String str = scan.nextLine();
        Set<Character> set = new HashSet<>();
        Set<Character> repeatedCharSet = new HashSet<>();
        for (int i = 0; i < str.length(); i++) {
            if (set.contains(str.charAt(i))) {
                repeatedCharSet.add(str.charAt(i));
            }
            set.add(str.charAt(i));

        }
        System.out.println(repeatedCharSet);
        scan.close();
    }

}

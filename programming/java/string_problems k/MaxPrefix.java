import java.util.*;

public class MaxPrefix {
    public static void main(String args[]) {
        ArrayList<String> arr = new ArrayList<String>();
        arr.addAll(Arrays.asList("geeksforgeeks", "geeks", "geek", "geeker"));
        System.out.println(arr);
        String prefix = arr.get(0);
        String tmp = "";
        for (String i : arr) {
            if (i.contains(prefix) == true) {
                continue;
            } else {
                tmp = "";
                for (int j = 0; j < i.length(); j++) {
                    if (j >= prefix.length()) {
                        break;
                    }
                    if (i.charAt(j) == prefix.charAt(j))
                        tmp = tmp + i.charAt(j);
                    else
                        break;
                }
                prefix = tmp;

            }

        }
        System.out.println(prefix);
    }

}

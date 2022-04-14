import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        String str = scan.nextLine();
        char arr[] = str.toCharArray();
        HashMap<Character, Integer> map = new HashMap<>();
        for (char i : arr) {
            if (map.containsKey(i) == false) {
                map.put(i, 1);
            } else
                map.put(i, map.get(i) + 1);
        }

        System.out.println(map);
    }

}

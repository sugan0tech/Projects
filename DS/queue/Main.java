import java.lang.reflect.Array;
import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner scn = new Scanner(System.in);
        Map<Character, Integer> map = new TreeMap<Character, Integer>();
        String s = scn.nextLine();
        int k = scn.nextInt();
        for (char i : s.toCharArray()) {
            if (map.containsKey(i))
                map.put(i, map.get(i) + 1);
            else
                map.put(i, 1);
        }
        System.out.println(map);
        ArrayList<Integer> arr = new ArrayList<>(map.values());
        LinkedList<Integer> que = new LinkedList<>();
        Collections.sort(arr, Collections.reverseOrder());
        for (Integer i : arr)
            que.add(i);
        System.out.println(que);

    }
}


    
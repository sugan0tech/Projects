import java.util.HashMap;

public class Kavin {
    public static void main(String args[]) {
        int arr[] = { 1, 2, 3, 5, 6, 2, 3, 4, 5 };
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i : arr) {
            if (map.containsKey(i))
                map.put(i, map.get(i) + 1);
            else
                map.put(i, 1);
        }
        System.out.println(map.keySet());
        System.out.println(map.values());

    }

}

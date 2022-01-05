import java.util.HashMap;

public class Hashmap {

    public static void main(String[] args) {
        HashMap<String, String> map = new HashMap<String, String>();
        map.put("key", "value");
        map.put("1", "value");// can have any kinda of value
        map.put("id", "test");
        System.out.println(map.get("id")); // gives value
        System.out.println(map.remove("id"));
        System.out.println(map.get("id")); // returns null
        System.out.println(map);
        System.out.println(map.keySet()); // gives set of keys
        System.out.println(map.size());
        map.clear(); // same as in ArrayList

    }
}

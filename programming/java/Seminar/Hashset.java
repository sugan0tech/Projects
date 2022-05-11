
import java.util.HashSet;

public class Hashset {

    public static void main(String[] args) {
        // No indexing on sets / no key value pairs
        HashSet<String> map = new HashSet<String>();
        map.add("value");
        map.add("value");// can have any kinda of value
        map.add("test");
        System.out.println(map.contains("id")); // gives value
        System.out.println(map.contains("test")); // returns null
        System.out.println(map);
        System.out.println(map.size());
        map.clear(); // same as in ArrayList

    }
}

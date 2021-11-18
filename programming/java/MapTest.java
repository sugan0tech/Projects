import java.util.*;

public class MapTest {
    public static void main(String[] args) {
        TreeMap<Integer, String> tst = new TreeMap<Integer, String>();
        tst.put(146, "jack");
        tst.put(127, "Dolittle");
        tst.put(152, "Heidi");
        tst.put(137, "Girig");
        tst.put(133, "Rambo");
        tst.put(129, "Ryder");
        tst.put(125, "Doctor");
        System.out.println(tst);
        for (Integer i : tst.keySet()) {
            System.out.println("key :" + i + "\tvalue :" + tst.get(i));
        }
    }
}

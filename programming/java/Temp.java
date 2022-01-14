import java.util.*;

public class Temp {
    public static void main(String[] args) {
        /* Array Declaration and initialization */
        Integer array[] = { 1, 2, 3, 4, 5 };

        /* ArrayList declaration */
        ArrayList<Integer> arraylist = new ArrayList<Integer>();

        /* Conversion */
        Collections.addAll(arraylist, array);

        /* Adding new elements to the converted List */
        arraylist.add("String1");
        arraylist.add("String2");

        /* Display array list */
        for (String str : arraylist) {
            System.out.println(str);
        }

    }
}
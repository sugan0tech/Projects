import java.util.ArrayList;
import java.util.Collections;
import java.util.function.Consumer;

public class ArrayLst {
    public static void main(String[] args) {
        ArrayList<Integer> arr = new ArrayList<Integer>();
        // .add() method to add elements to the arr ArrayList object
        arr.add(1);
        arr.add(2);
        arr.add(3);
        arr.add(4);
        arr.add(5);
        arr.forEach((n) -> {
            System.out.println(n);
        });
        // .get(i) to get i'th element where i is the index
        System.out.println(arr.get(1));
        // .size() gives the size of array
        System.out.println(arr.size());
        /*
         * .set(i, e) to change element at a index
         * i => index
         * e => element
         */
        arr.set(1, 3);
        System.out.println(arr);
        // .remove(i) to remove element at i'th index
        arr.remove(2);
        System.out.println(arr);

        // for iterations .forEach(method) is used
        Consumer<Integer> method = (n) -> {
            System.out.println(n);
        };
        arr.forEach(method);
        // iterating with for loops
        for (Integer i : arr) {
            System.out.println(i);
        }
        // .clear() to clear all the values in the array
        arr.clear();
        System.out.println(arr); // gives empty array

        // .equals Demonstration;
        // implemented by hashcode in the background
        ArrayList<Integer> test = new ArrayList<>(arr);
        test.add(4);
        System.out.println(test.equals(arr));
    }

}
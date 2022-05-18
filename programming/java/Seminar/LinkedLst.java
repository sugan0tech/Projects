import java.util.LinkedList;
import java.util.function.Consumer;

public class LinkedLst {
    public static void main(String[] args) {
        LinkedList<Integer> lst = new LinkedList<Integer>();
        lst.addFirst(6);
        lst.addLast(7);
        System.out.println(lst.getFirst());
        System.out.println(lst.getLast());
        lst.removeFirst();
        lst.removeLast();

        // .add() method to add elements to the arr ArrayList object
        lst.add(1);
        lst.add(2);
        lst.add(3);
        lst.add(4);
        lst.add(5);

        // .get(i) to get i'th element where i is the index
        System.out.println(lst.get(1));

        // .size() gives the size of array
        System.out.println(lst.size());

        /*
         * .set(i, e) to change element at a index
         * i => index
         * e => element
         */
        lst.set(1, 3);
        System.out.println(lst);

        // .remove(i) to remove element at i'th index
        lst.remove(2);
        System.out.println(lst);

        // for iterations .forEach(method) is used
        Consumer<Integer> method = (n) -> {
            System.out.println(n);
        };
        lst.forEach(method);

        // iterating with for loops
        for (Integer i : lst) {
            System.out.println(i);
        }

        // .clear() to clear all the values in the array
        lst.clear();
        System.out.println(lst); // gives empty array

    }

}

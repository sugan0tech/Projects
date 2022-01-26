import java.util.*;

public class Matrix {
    public static void main(String args[]) {
        ArrayList<Integer> intList = new ArrayList<Integer>();
        ArrayList<ArrayList<Integer>> mainList = new ArrayList<ArrayList<Integer>>();
        for (int i = 0; i < 5; i++) {
            intList = new ArrayList<Integer>();
            for (int j = 0; j < 5; j++) {
                intList.add(j);
            }
            mainList.add(intList);
        }
        System.out.println(mainList);

        for (ArrayList<Integer> i : mainList) {
            System.out.println(i);
        }
    }

}

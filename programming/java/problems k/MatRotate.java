import java.util.*;

public class MatRotate {
    public static void main(String args[]) {
        ArrayList<Integer> arr1 = new ArrayList<Integer>(Arrays.asList(1, 2, 3, 4, 5));
        ArrayList<ArrayList<Integer>> mat = new ArrayList<ArrayList<Integer>>(
                List.of(
                        arr1,
                        arr1,
                        arr1,
                        arr1,
                        arr1));
        System.out.println("\nMatrix in normal form\n");
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat.get(i).size(); j++) {
                System.out.print(mat.get(i).get(j) + " ");
            }
            System.out.println();
        }
        System.out.println("\nMatrix in rotated form\n");
        for (int i = mat.size() - 1; i >= 0; i--) {
            for (int j = mat.get(i).size() - 1; j >= 0; j--) {
                System.out.print(mat.get(i).get(j) + " ");
            }
            System.out.println();
        }
        System.out.println();

    }

}
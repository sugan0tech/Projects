import java.util.*;
import java.util.function.Consumer;

public class Lambda {
    public static void main(String args[]) {
        TestClass obj = new TestClass();
        obj.print("hi");
        printTest(obj);
        Test lambda = str -> System.out.println(str + "hi there");
        printTest(lambda);

        // Collections example
        List<Integer> lst = new ArrayList<>();
        Integer arr[] = { 1, 2, 3, 4, 5, 6 };
        lst.addAll(Arrays.asList(arr));

        Consumer<Integer> printConsumer = num -> System.out.println(num);
        lst.forEach(printConsumer);

    }

    static void printTest(Test thing) {
        thing.print("$");
    }
}
import java.util.*;

class Test<T> {
    T obj;

    Test(T obj) {
        this.obj = obj;
    }

    public T getObject() {
        return this.obj;
    }

}

public class Generic {
    public static void main(String args[]) {
        Integer num = Integer.valueOf(8);
        ArrayList<Integer> arr = new ArrayList<>();
        arr.add(3);
        arr.add(4);
        arr.add(5);
        arr.add(6);
        Test<Integer> obj1 = new Test<Integer>(num);
        Test<ArrayList> obj2 = new Test<ArrayList>(arr);

        System.out.println(obj1.getObject());
        System.out.println(obj2.getObject());
    }
}

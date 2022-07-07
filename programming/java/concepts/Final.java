import java.util.*;

public class Final {
    public static void main(String args[]) {
        final int n = 2;
        System.out.println(n);
        final Final obj = new Final();
        obj.sayHi();
    }

    public void sayHi() {
        System.out.println("bla");
    }

}

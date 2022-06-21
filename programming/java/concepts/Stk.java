import java.util.*;

public class Stk {
    public static void main(String args[]) {
        Integer a = 10;
        Stack<Integer> stk = new Stack<>();
        stk.push(1);
        System.out.println(stk.peek());
        System.out.println(stk.pop());
        System.out.println(stk.size());
    }

}

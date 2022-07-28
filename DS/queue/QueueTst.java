import java.util.*;

public class QueueTst {
    public static void main(String args[]) {
        LinkedList<Integer> que = new LinkedList<>();
        que.add(1);
        que.add(2);
        que.add(3);
        que.add(4);
        System.out.println(que);
        System.out.println(que.remove());
        System.out.println(que);
    }
}
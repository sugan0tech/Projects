import java.util.Queue;
import java.util.LinkedList;

public class Queuee {
    public static void main(String[] args) {
        Queue<Integer> que = new LinkedList<Integer>();
        que.add(1);
        que.add(2);
        que.add(3);
        que.add(4);
        que.add(5);
        System.out.println(que.size());
        System.out.println(que);
        System.out.println(que.poll()); // removes head
        System.out.println(que.peek()); // gives head
        que.clear();

    }
}
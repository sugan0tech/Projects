import java.util.*;

class Node {
    int value;
    Node next;

    Node(int value) {
        this.value = value;
        this.next = null;
    }
}

class Queue {
    Node front;
    Node rear;
    Node temp;

    Queue() {
        this.front = null;
        this.rear = null;
    }

    void enqueue(int n) {
        temp = new Node(n);
        if (this.rear == null) {
            this.front = temp;
            this.rear = temp;
        } else {
            this.rear.next = temp;
            this.rear = temp;
        }
    }

    int deque() {
        temp = this.front;
        if (temp == null)
            return -1;
        this.front = this.front.next;
        return temp.value;
    }

    @Override
    public String toString() {
        temp = this.front;
        String res = "";
        while (temp != null) {
            res += temp.value + " ";
            temp = temp.next;
        }
        return res;
    }
}

public class QueueLL {
    public static void main(String args[]) {
        Queue que = new Queue();
        que.enqueue(1);
        que.enqueue(2);
        que.enqueue(3);

        System.out.println(que);
        System.out.print(que.deque());
        System.out.print(que.deque());
    }
}

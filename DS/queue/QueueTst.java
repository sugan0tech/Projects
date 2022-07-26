import java.util.*;

class Node {
    private int value;
    private Node next = null;

    Node() {
    }

    Node(Node node) {
        this.value = node.getValue();
        node.next = node.getNext();
    }

    Node(int value) {
        this.value = value;
        this.next = null;
    }

    Node(int value, Node next) {
        this.value = value;
        this.next = next;
    }

    void putNext(Node next) {
        this.next = next;
    }

    Node getNext() {
        return this.next;
    }

    int getValue() {
        return this.value;
    }

    @Override
    public String toString() {
        return "Value : " + this.value;
    }
}

class Queue {
    private Node front = null;
    private Node rear = null;
    private int size = 0;

    Queue() {

    }

    void enque(int value) {
        Node tmp = new Node(value);
        if (front == null) {
            this.front = tmp;
            this.front.putNext(null);
            this.rear = front;
        } else {
            tmp.putNext(rear);
            rear = tmp;
        }
        this.size++;
    }

    int deque() {
        if (this.rear == null)
            return -1;
        Node tmp = new Node(this.rear);
        this.rear = this.rear.getNext();
        this.size--;
        return tmp.getValue();
    }

    public int size() {
        return this.size;
    }

    @Override
    public String toString() {
        String str = "Rear : ";
        Node tmp = this.rear;

        while (tmp.getNext() != null) {
            str += tmp.getValue() + "->";
            tmp = tmp.getNext();
        }
        str += tmp.getValue() + "";
        str += " : Front";
        return str;
    }

}

public class QueueTst {
    public static void main(String args[]) {
        Queue que = new Queue();
        que.enque(1);
        que.enque(2);
        que.enque(3);
        que.enque(4);
    }

}

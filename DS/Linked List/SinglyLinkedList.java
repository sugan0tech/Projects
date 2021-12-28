import java.util.*;

class Node {
    int data;
    Node next;

    public Node() {
        data = 0;
    }

    public Node(int val) {
        data = val;
    }
}

public class SinglyLinkedList {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int option, data;
        Node Head = null, temp = new Node(), neww = new Node();
        System.out.println(
                "1 for creating new Linked \n" +
                        "2 for printing Linked List \n" +
                        "3 for adding element to first index \n" +
                        "4 for appending\n" +
                        "5 for adding element at desired place\n" +
                        "6 for deleting an element");

        option = scan.nextInt();
        while (option != 0) {
            switch (option) {
                case 1:
                    System.out.println("\nEnter the node data :");
                    data = scan.nextInt();
                    while (data != 0) {

                        neww = new Node();
                        neww.data = data;
                        if (Head == null) {
                            Head = neww;
                            temp = Head;
                        } else {
                            temp.next = neww;
                            temp = temp.next;
                            temp.next = null;
                        }
                        System.out.println("\nEnter the node data :");
                        data = scan.nextInt();
                    }
                    break;

                case 2:
                    temp = Head;
                    while (temp != null) {
                        System.out.println(temp.data);
                        temp = temp.next;
                    }
                    break;

                case 3:
                    break;
                default:
                    break;
            }

            System.out.println(
                    "1 for creating new Linked \n" +
                            "2 for printing Linked List \n" +
                            "3 for adding element to first index \n" +
                            "4 for appending\n" +
                            "5 for adding element at desired place\n" +
                            "6 for deleting an element");
            option = scan.nextInt();
        }
    }

}

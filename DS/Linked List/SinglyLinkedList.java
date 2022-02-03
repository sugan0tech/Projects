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
        Node head = null, temp = new Node(), neww = new Node();
        System.out.println(
                "\n1 for creating new Linked \n" +
                        "2 for printing Linked List \n" +
                        "3 for adding element to first index \n" +
                        "4 for appending\n" +
                        "5 for adding element at desired place\n" +
                        "6 for deleting an element");
        System.out.print("\n Enter the option :");
        option = scan.nextInt();
        while (option != 0) {
            switch (option) {
                case 1:
                    System.out.print("\n   Enter the node data :");
                    data = scan.nextInt();
                    while (data != 0) {

                        neww = new Node();
                        neww.data = data;
                        if (head == null) {
                            head = neww;
                            temp = head;
                        } else {
                            temp.next = neww;
                            temp = temp.next;
                            temp.next = null;
                        }
                        System.out.print("   Enter the node data :");
                        data = scan.nextInt();
                    }
                    break;

                case 2:
                    temp = head;
                    System.out.print("\n    " + temp.data);
                    temp = temp.next;
                    while (temp != null) {
                        System.out.print(" - > " + temp.data);
                        temp = temp.next;
                    }
                    break;

                case 3:
                    System.out.print("\n   Enter the node data :");
                    data = scan.nextInt();
                    neww = new Node(data);
                    neww.next = head;
                    head = neww;
                    break;
                case 4:
                    System.out.print("\n   Enter the node data :");
                    data = scan.nextInt();
                    temp = head;
                    while (temp.next != null) {
                        temp = temp.next;
                    }
                    temp.next = new Node(data);
                    break;
                case 5:
                    System.out.print("\n Enter the index val :");
                    int n = scan.nextInt();
                    System.out.print("\n   Enter the node data :");
                    data = scan.nextInt();
                    temp = head;
                    while (n > 0) {
                        temp = temp.next;
                        n--;
                    }
                    neww = temp.next;
                    temp.next = new Node(data);
                    temp.next.next = neww;
                    break;
                case 6:
                    System.out.print("\n   Enter the node data :");
                    data = scan.nextInt();
                    temp = head;
                    while (temp.next != null) {
                        if (temp.next.data == data) {
                            temp.next = temp.next.next;
                            break;
                        }
                        temp = temp.next;
                    }
                    break;
                default:
                    break;
            }

            System.out.println(
                    "\n\n1 for creating new Linked \n" +
                            "2 for printing Linked List \n" +
                            "3 for adding element to first index \n" +
                            "4 for appending\n" +
                            "5 for adding element at desired place\n" +
                            "6 for deleting an element");
            System.out.print("\n  Enter the option :");
            option = scan.nextInt();
        }
        scan.close();
    }

}

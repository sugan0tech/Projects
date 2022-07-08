class Node {
    int data;
    int bf;
    int h;
    Node left = null;
    Node right = null;

    Node() {
        this.data = 0;
    }

    Node(int data) {
        this.data = data;
        this.h = 0;
        this.bf = 0;
    }
}

class Tree {
    Node root;

    Tree() {
        this.root = null;
    }

    Tree(Node root) {
        this.root = root;
    }

    void insert(Node node) {
        this.root = _insert(this.root, node);
    }

    private Node _insert(Node root, Node node) {

        if (root == null)
            root = node;
        else {
            if (root.data > node.data) {
                root.left = _insert(root.left, node);
            } else {
                root.right = _insert(root.right, node);
            }
        }
        root = update(root);
        return balance(root);
    }

    Node update(Node node) {
        int lh = -1;
        int rh = -1;
        if (node.left != null)
            lh = node.left.h;
        if (node.right != null)
            rh = node.right.h;
        node.h = 1 + Math.max(lh, rh);
        node.bf = rh - lh;
        return node;
    }

    Node balance(Node node) {
        if (node.bf == -2) // Left originated case
        {
            if (node.left.bf <= 0) // LeftLeft case
            {
                return leftLeftCase(node);

            } else // LeftRight case
            {
                return leftRightCase(node);
            }
        } else if (node.bf == 2) // Right originated case
        {
            if (node.right.bf >= 0)// RightRight case
            {
                return rightRightCase(node);
            } else// RightLeft case
            {
                return rightLeftCase(node);
            }

        }
        return node;
    }

    // Rotation cases
    Node leftLeftCase(Node node) {
        return rightRotation(node);
    }

    Node leftRightCase(Node node) {
        node.left = leftRotation(node.left);
        return leftLeftCase(node);
    }

    Node rightRightCase(Node node) {
        return leftRotation(node);
    }

    Node rightLeftCase(Node node) {
        node.right = rightRotation(node.right);
        return rightRightCase(node);

    }

    // Rotations
    Node leftRotation(Node A) {
        Node B = A.right;
        A.right = B.left;
        B.left = A;
        A = update(A);
        B = update(B);
        return B;
    }

    Node rightRotation(Node A) {
        Node B = A.left;
        A.left = B.right;
        B.right = A;
        A = update(A);
        B = update(B);
        return B;
    }

    void inOrder() {
        _inOrder(this.root);
    }

    private void _inOrder(Node node) {
        if (node != null) {
            _inOrder(node.left);
            System.out.println("data\theight\tbf");
            System.out.println(node.data + "\t" + node.h + "\t" + node.bf);
            _inOrder(node.right);
        }
    }
}

public class AVL {
    public static void main(String args[]) {
        Tree tree = new Tree(new Node(5));
        tree.insert(new Node(4));
        tree.insert(new Node(6));
        tree.insert(new Node(8));
        tree.insert(new Node(2));
        tree.insert(new Node(1));
        tree.insert(new Node(3));
        tree.insert(new Node(7));
        tree.inOrder();

    }
}
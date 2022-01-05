import java.util.*;

public class Ds {

    public class k {
        private int data;

        public k() {
            data = 0;
        };

        public k(int x) {
            data = x;
        };
    }

    public static void main(String[] args) {
        k me = new k(2);
        System.out.println(me.data);
    }
}
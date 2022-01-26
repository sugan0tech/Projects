import java.util.*;

public class First {
    public static void main(String[] args) {

        Second.print();
        Second tat = new Second();
        for (Object i : args) {
            System.out.println(i);
        }

    }

}
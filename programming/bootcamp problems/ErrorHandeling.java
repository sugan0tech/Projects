import java.util.*;

public class ErrorHandeling {
    public static void main(String args[]) {
        try {
            throw new RuntimeException();
        } catch (Exception e) {
            System.out.println(e);
        }
    }

}

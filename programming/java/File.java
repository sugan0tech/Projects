import java.util.*;

public class File {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int i = 1;
        while (s.hasNext()) {
            System.out.println(i + " " + s.nextLine());
            i++;
        }
        s.close();
    }
}
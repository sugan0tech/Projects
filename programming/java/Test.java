import java.util.Scanner;

public class Test {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String str = scan.nextLine();
        String res = "";
        int i = 0;
        int count;
        while (i < str.length()) {
            count = 1;
            while ((i < str.length() - 1) && str.charAt(i) == str.charAt(i + 1)) {
                count++;
                i++;
            }
            res = res + Character.toString(str.charAt(i)) + count;
            i++;
        }
        System.out.println(res);
        scan.close();
    };

}
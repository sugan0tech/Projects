import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class XMLextractor {
    public static void main(String args[]) {
        Scanner scn = new Scanner(System.in);
        String line = scn.nextLine();
        Pattern p = Pattern.compile("<([\\w\\d]*)>([^<]+)</\\1>");
        Matcher m = p.matcher(line);
        System.out.println(m.find());
        System.out.println(m.group());

        scn.close();
    }
}
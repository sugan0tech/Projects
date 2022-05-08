import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.*;

public class PatternHR {
    public static void main(String args[]) {
        Pattern p = Pattern.compile("\bword\b");
        Matcher m = p.matcher("2kdwordsidi");
        System.out.println(m.matches());
    }

}
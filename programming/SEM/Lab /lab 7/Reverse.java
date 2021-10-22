import static org.junit.Assert.assertEquals;
import org.junit.Test;

public class Reverse {
    public static void main(String args[]) {
    }

    public static String reverseastring(String a) {
        char ch[] = a.toCharArray();
        String rev = "";
        for (int i = ch.length - 1; i >= 0; i--) {
            rev += ch[i];
        }
        return rev;
    }

    @Test
    public void Test1() {
        assertEquals("olleH", reverseastring("Hello"));
    }

    @Test
    public void Test2() {
        assertEquals("emocleW", reverseastring("Welcome"));
    }

    @Test
    public void Test3() {
        assertEquals("ESC", reverseastring("CSE"));
    }

    @Test
    public void Test4() {
        assertEquals("eniF", reverseastring("Fine"));
    }

    @Test
    public void Test5() {
        assertEquals("meS", reverseastring("Sem"));
    }
}
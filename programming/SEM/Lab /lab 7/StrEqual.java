import static org.junit.Assert.assertEquals;
import org.junit.Test;

public class StrEqual {
    public static void main(String[] args) {

    }

    public static String stringequalornot(String a, String b) {
        if (a == b) {
            return "Equal";
        } else {
            return "Not Equal";
        }
    }

    @Test
    public void Test1() {
        assertEquals("Equal", stringequalornot("Hello", "Hello"));
    }

    @Test
    public void Test2() {
        assertEquals("Not Equal", stringequalornot("Welcome", "Hi"));
    }

    @Test
    public void Test3() {
        assertEquals("Equal", stringequalornot("CSE", "CSE"));
    }

    @Test
    public void Test4() {
        assertEquals("Not Equal", stringequalornot("Sem", "Lab"));
    }

    @Test
    public void Test5() {
        assertEquals("Equal", stringequalornot("Fine", "Fine"));
    }
}
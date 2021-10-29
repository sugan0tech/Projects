import static org.junit.Assert.assertEquals;
import org.junit.Test;

public class StrEqual {
    public static void main(String[] args) {
        String a = "SEM";
        String b = "SEM";
        System.out.println(stringequalornot(a, b));

    }

    public static String stringequalornot(String a, String b) {
        if (a == b) {
            return "Equal";
        } else {
            return "Not Equal";
        }
    }

    @Test
    public void Test_1() {
        assertEquals("Equal", stringequalornot("Hello", "Hello"));
    }

    @Test
    public void Test_2() {
        assertEquals("Not Equal", stringequalornot("Welcome", "Hi"));
    }

    @Test
    public void Test_3() {
        assertEquals("Equal", stringequalornot("CSE", "CSE"));
    }

    @Test
    public void Test_4() {
        assertEquals("Not Equal", stringequalornot("Sem", "Lab"));
    }

    @Test
    public void Test_5() {
        assertEquals("Equal", stringequalornot("Fine", "Fine"));
    }
}
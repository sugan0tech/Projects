import static org.junit.Assert.assertEquals;
import org.junit.Test;

public class Prime {
    public static void main(String args[]) {
    }

    public static String prmie_check(int n) {
        int i, m = 0;
        m = n / 2;
        if (n == 0 || n == 1) {
            return "not a prime";
        } else {
            for (i = 2; i <= m; i++) {
                if (n % i == 0) {
                    return "not a prime";
                }
            }
            return "prime";

        }

    }

    @Test
    public void Test1() {
        assertEquals("prime", prmie_check(3));
    }

    @Test
    public void Test2() {
        assertEquals("not a prime", prmie_check(8));
    }

    @Test
    public void Test3() {
        assertEquals("prime", prmie_check(19));
    }

    @Test
    public void Test4() {
        assertEquals("not a prime", prmie_check(18));
    }

    @Test
    public void Test5() {
        assertEquals("prime", prmie_check(89));
    }
}
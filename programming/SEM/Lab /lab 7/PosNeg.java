import static org.junit.Assert.assertEquals;
import org.junit.Test;

public class PosNeg {

    public static void main(String[] args) {
        int num = 8;
        int res = pos_neg(num);
        if (res == 1) {
            System.out.println(" positive ");
        } else {
            System.out.println(" negative ");
        }
    }

    public static int pos_neg(int num) {
        if (num > 0) {
            return 1;
        } else {
            return 0;
        }

    }

    @Test
    public void Test1() {

        assertEquals(1, pos_neg(1));

    }

    @Test
    public void Test2() {

        assertEquals(1, pos_neg(4));
    }

    @Test
    public void Test3() {

        assertEquals(0, pos_neg(-9));
    }

    @Test
    public void Test4() {

        assertEquals(1, pos_neg(2));
    }

    @Test
    public void Test5() {

        assertEquals(0, pos_neg(-11));
    }
}
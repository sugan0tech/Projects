import static org.junit.Assert.assertEquals;
import org.junit.Test;

public class OddEven {

    public static void main(String[] args) {
        int num = 8;
        int res = odd_even(num);
        if (res == 1) {
            System.out.println(" Even ");
        } else {
            System.out.println(" Odd ");
        }
    }

    public static int odd_even(int num) {
        if (num % 2 == 0) {
            return 1;
        } else {
            return 0;
        }

    }

    @Test
    public void Test_1() {

        assertEquals(0, odd_even(1));

    }

    @Test
    public void Test_2() {

        assertEquals(1, odd_even(4));
    }

    @Test
    public void Test_3() {

        assertEquals(0, odd_even(9));
    }

    @Test
    public void Test_4() {

        assertEquals(1, odd_even(2));
    }

    @Test
    public void Test_5() {

        assertEquals(0, odd_even(11));
    }
}
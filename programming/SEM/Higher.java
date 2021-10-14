import static org.junit.Assert.assertEquals;
import org.junit.Test;

public class Higher {

    public static void main(String[] args) {

        int a = 25;
        int b = -25;
        int c = higher(a, b);
        System.out.println("The higher of 25 and -25 is " + c);
    }

    /*
     * @param a
     * 
     * @param b
     * 
     * @return the higher of two values
     *
     */
    public static int higher(int x, int y) {
        if (x > y) {
            return x;
        } else
            return y;

    }

    @Test
    public void Test1() {

        assertEquals(25, higher(25, 25));
    }

    @Test
    public void Test2() {

        assertEquals(5, higher(5, 3));
    }

    @Test
    public void Test3() {

        assertEquals(7, higher(2, 7));
    }

    @Test
    public void Test4() {

        assertEquals(42, higher(3, 42));
    }

    @Test
    public void Test5() {

        assertEquals(27, higher(25, 27));
    }
}
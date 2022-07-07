import java.util.*;

class Don {
    private String gf = "secret";
    public String name = "vikram";

    public static void kissHand() {
        System.out.println("done");
    }
}

class Aprm extends Don {

}

public class Inheritance {
    public static void main(String args[]) {
        Aprm bois = new Aprm();
        System.out.println(bois.gf);

    }

}

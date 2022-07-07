import java.util.*;

abstract class Don {
    int num = 4;

    abstract void getGF();

    void getAttitude() {
        System.out.println("I am a Boss");
    }
}

class Vikram extends Don {
    void getGF() {
        System.out.println("VikramHub");
    }
}

public class Abstract {
    public static void main(String args[]) {
        Vikram viki = new Vikram();
        viki.getGF();
        viki.getAttitude();
        System.out.println(viki.num);

    }
}

import javax.swing.plaf.synth.SynthScrollBarUI;

public class DataTypes {
    int a = 4;
    static int c = 2;

    public static void main(String args[]) {

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (j == 3)
                    break;
                System.out.println(j);
            }
        }
    }

}

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutput;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.*;

class Beans implements Serializable {
    // all members should be private
    private int data;
    private String strData;

    // Must have parameter less constructor
    Beans() {
        this.data = 0;
        this.strData = new String();
    }

    Beans(int data, String strData) {
        this.data = data;
        this.strData = strData;
    }

    // only getters and setters to access datamembers
    void setData(int data) {
        this.data = data;
    }

    void setStrData(String strData) {
        this.strData = strData;
    }

    int getData() {
        return this.data;
    }

    String getStrData() {
        return this.strData;
    }

    void print() {
        System.out.println("Welcome to the beans object");
    }

}

public class Bean {
    public static void main(String args[]) {
        Beans b = new Beans(1, "hi there");
        String filename = "sug.obj";

        try {
            FileOutputStream file = new FileOutputStream(filename);
            ObjectOutputStream oStream = new ObjectOutputStream(file);
            oStream.writeObject(b);
            oStream.close();
            file.close();
            System.out.println("object has been stored");

        } catch (IOException e) {
            System.out.println(e);
        } catch (SecurityException s) {
            System.out.println(s);
        }

        Beans b2;
        try {
            FileInputStream file = new FileInputStream(filename);
            ObjectInputStream oStream = new ObjectInputStream(file);
            b2 = (Beans) oStream.readObject();
            System.out.println("object retrived successfully");
            b2.print();
            file.close();
            oStream.close();

        } catch (IOException i) {
            System.out.println(i);
        } catch (ClassNotFoundException c) {
            System.out.println(c);
        } catch (SecurityException s) {
            System.out.println(s);
        }

    }
}
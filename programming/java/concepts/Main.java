import java.util.*;

class Item {
    String name;
    double price;

    Item(String name, double price) {
        this.name = name;
        this.price = price;
    }
}

interface ITEMS {
    public static HashMap<String, Item> map = new HashMap<>() {
        {
            put("1", new Item("Tomato", 5.23));
            put("2", new Item("Potato", 86.234));
            put("3", new Item("Onion", 100.0));
            put("4", new Item("Orange", 50.5));
        }
    };

}

interface DETAILS {
    void getPrice(String code);

    void getName(String code);
}

class shop implements DETAILS, ITEMS {
    public void getPrice(String code) {
        if (map.containsKey(code))
            System.out.println(map.get(code).price);
        else
            System.out.println("Not Found");
    }

    public void getName(String code) {
        if (map.containsKey(code))
            System.out.print(map.get(code).name);
        else
            System.out.print("Not Found");
    }
}

public class Main {
    public static void main(String args[]) {
        Scanner scn = new Scanner(System.in);
        System.out.print("\nEnter the Product Id :");
        String id = scn.nextLine();
        shop plaa = new shop();
        System.out.print("\nProduct name :");
        plaa.getName(id);
        System.out.print("\nProduct Price :");
        plaa.getPrice(id);
    }
}

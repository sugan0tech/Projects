import java.util.*;

class PrimeManagement {
    private int primeId;
    private String userProfileName;
    private String subscriptionType;
    private double subscriptionPrice;
    private int noOfProfiles;

    public PrimeManagement(int pid, String upn, String spt, double sp, int nop) {
        primeId = pid;
        userProfileName = upn;
        subscriptionType = spt;
        subscriptionPrice = sp;
        noOfProfiles = nop;
    }

    public PrimeManagement() {
        primeId = 0;
        userProfileName = "";
        subscriptionType = "";
        subscriptionPrice = 0;
        noOfProfiles = 0;
    }

    // setters
    public void setPrimeId(int pid) {
        primeId = pid;
    }

    public void setuserProfileName(String upn) {
        userProfileName = upn;
    }

    public void setSubscritptionType(String st) {
        subscriptionType = st;
    }

    public void setSubscritptionPrice(double scp) {
        subscriptionPrice = scp;
    }

    public void setNoofProfiles(int nop) {
        noOfProfiles = nop;
    }

    // getters
    public int getPrimeId() {
        return primeId;
    }

    public String getuserProfileName() {
        return userProfileName;
    }

    public String getSubscritptionType() {
        return subscriptionType;
    }

    public double getSubscritptionPrice() {
        return subscriptionPrice;
    }

    public int getNoofProfiles() {
        return noOfProfiles;
    }

    public void print() {
        System.out.println(primeId);
        System.out.println(userProfileName);
        System.out.println(subscriptionType);
        System.out.println(subscriptionPrice);
        System.out.println(noOfProfiles);
    }

}

public class MyClass {
    public static int findAvgPriceByType(PrimeManagement[] A, String str) {

        int avg = 0, count = 0;
        for (PrimeManagement i : A) {
            if (str == i.getSubscritptionType()) {
                if (i.getNoofProfiles() > 3) {
                    avg += i.getSubscritptionPrice();
                    count++;
                }
            }
        }
        if (avg > 0)
            avg = avg / count;
        return avg;
    }

    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        PrimeManagement data[] = new PrimeManagement[4];
        data[0] = new PrimeManagement();
        data[0].setPrimeId(1005);
        data[0].setuserProfileName("Mani");
        data[0].setSubscritptionType("monthly");
        data[0].setSubscritptionPrice(100);
        data[0].setNoofProfiles(4);
        data[1] = new PrimeManagement();
        data[1].setPrimeId(1001);
        data[1].setuserProfileName("Sathish");
        data[1].setSubscritptionType("monthly");
        data[1].setSubscritptionPrice(300);
        data[1].setNoofProfiles(2);
        data[2] = new PrimeManagement();
        data[2].setPrimeId(1007);
        data[2].setuserProfileName("John");
        data[2].setSubscritptionType("yearly");
        data[2].setSubscritptionPrice(500);
        data[2].setNoofProfiles(5);
        data[3] = new PrimeManagement();
        data[3].setPrimeId(1003);
        data[3].setuserProfileName("Joe");
        data[3].setSubscritptionType("monthly");
        data[3].setSubscritptionPrice(400);
        data[3].setNoofProfiles(5);
        String str = "monthly";

        System.out.println(findAvgPriceByType(data, str));
    }
}
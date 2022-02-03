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

}

public class Main {
    public static void main(String args[]) {

    }

}

import java.util.*;

public class TestClass {
    static int maxProfit(int price[], int n) {
        int profit[] = new int[n];
        for (int i = 0; i < n; i++)
            profit[i] = 0;
        int max_price = price[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (price[i] > max_price)
                max_price = price[i];
            profit[i] = Math.max(profit[i + 1],
                    max_price - price[i]);
        }

        int min_price = price[0];
        for (int i = 1; i < n; i++) {
            if (price[i] < min_price)
                min_price = price[i];
            profit[i] = Math.max(
                    profit[i - 1],
                    profit[i] + (price[i] - min_price));
        }
        int result = profit[n - 1];
        return result;
    }

    public static void main(String args[]) {
        int price[] = { 3, 3, 5, 0, 0, 3, 1, 4 };
        int n = price.length;
        System.out.println(maxProfit(price, n));
    }

}

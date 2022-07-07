import java.io.*;
import java.util.Scanner;
import java.util.StringTokenizer;

public class IO {
    public static void main(String args[]) throws Exception {
        BufferedReader bff = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer token = new StringTokenizer(bff.readLine(), "l");
        System.out.println(token.nextToken());
        System.out.println(token.nextToken());
        System.out.println(token.nextToken());
        bff.close();

    }
}
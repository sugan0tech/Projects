import java.util.*;

class Operations {
    int n;
    int[] numbers;

    Operations(int n) {
        this.n = n;
        numbers = new int[n];
    }

    public void readinput() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Reading numbers....");
        for (int i = 0; i < n; i++) {
            System.out.println("Enter the number: ");
            numbers[i] = sc.nextInt();
        }
    }

    public void greatest() {
        int max = this.numbers[0];
        for (int i = 1; i < n; i++) {
            if (this.numbers[i] > max) {
                System.out.println(numbers[i]);
                max = numbers[i];
            }
        }
        System.out.println("Biggest Of the given numbers: " + max);
    }

    public void count_oddnumbers() {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (numbers[i] % 2 == 0) {
                continue;
            } else {
                count++;
            }
        }
        System.out.println("Count Of Odd Numbers: " + count);
    }

    public void average() {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum = sum + numbers[i];
        }
        float avg;
        avg = (float) sum / n;
        System.out.println("Average: " + avg);
    }
}

class T1 implements Runnable {
    Operations op;

    T1(Operations op) {
        this.op = op;
        Thread t = new Thread(this);
        t.start();
    }

    public void run() {
        op.readinput();
    }
}

class T2 implements Runnable {
    Operations op;

    T2(Operations op) {
        this.op = op;
        Thread t = new Thread(this);
        t.start();
    }

    public void run() {
        op.greatest();
    }
}

class T3 implements Runnable {
    Operations op;

    T3(Operations op) {
        this.op = op;
        Thread t = new Thread(this);
        t.start();
    }

    public void run() {
        op.count_oddnumbers();
    }
}

class T4 implements Runnable {
    Operations op;

    T4(Operations op) {
        this.op = op;
        Thread t = new Thread(this);
        t.start();
    }

    public void run() {
        op.average();
    }
}

public class Threads {
    public static void main(String[] args) throws InterruptedException {
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter n: ");
        n = sc.nextInt();
        Operations op = new Operations(n);
        T1 a = new T1(op);
        T2 b = new T2(op);
        T3 c = new T3(op);
        T4 d = new T4(op);

    }
}
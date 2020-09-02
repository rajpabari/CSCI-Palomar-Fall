import java.lang.Math;

public class BigO {

    public static void bigOConstantTime(int n) {
        System.out.print("n : " + n + ": ");
    }

    public static void bigOLogNTime(int n) {
        System.out.print("n : " + n + ": ");
        for (int i = 1; i < n; i *= 2) {
            System.out.print("");
        }
        System.out.print(": ");
    }

    public static void bigONTime(int n) {
        System.out.print("n : " + n + ": ");
        for (int i = 1; i < n; i++) {
            System.out.print("");
        }
        System.out.print(": ");
    }

    public static void bigONLogNTime(int n) {
        System.out.print("n : " + n + ": ");
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j *= 2) {
                System.out.print("");
            }
        }
        System.out.print(": ");
    }

    public static void bigON2Time(int n) {
        System.out.print("n : " + n + ": ");
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                System.out.print("");
            }
        }
        System.out.print(": ");
    }

    public static void bigO2NTime(int n) {
        System.out.print("n : " + n + ": ");
        for (int i = 1; i < Math.pow(2, n); i++) {
            System.out.print("");
        }
        System.out.print(": ");
    }

    public static void main(String[] args) {
        System.out.println("==Big O Java==");
        System.out.println("Code by Raj Pabari");

        int[] nums = { 100, 1000, 10000, 100000, 10000000 };

        System.out.println("==O(1)==");
        for (int n : nums) {
            long timeStart = System.currentTimeMillis();
            bigOConstantTime(n);
            long timeEnd = System.currentTimeMillis();
            long duration = timeEnd - timeStart;
            System.out.println("millisecs: " + duration);
        }

        System.out.println("==O(Logn)==");
        for (int n : nums) {
            long timeStart = System.currentTimeMillis();
            bigOLogNTime(n);
            long timeEnd = System.currentTimeMillis();
            long duration = timeEnd - timeStart;
            System.out.println("millisecs: " + duration);
        }

        System.out.println("==O(n)==");
        for (int n : nums) {
            long timeStart = System.currentTimeMillis();
            bigONTime(n);
            long timeEnd = System.currentTimeMillis();
            long duration = timeEnd - timeStart;
            System.out.println("millisecs: " + duration);
        }

        System.out.println("==O(nLogn)==");
        for (int n : nums) {
            long timeStart = System.currentTimeMillis();
            bigONLogNTime(n);
            long timeEnd = System.currentTimeMillis();
            long duration = timeEnd - timeStart;
            System.out.println("millisecs: " + duration);
        }

        int[] quadraticNums = { 1, 10, 100, 1000 };
        System.out.println("==O(n^2)==");
        for (int n : quadraticNums) {
            long timeStart = System.currentTimeMillis();
            bigON2Time(n);
            long timeEnd = System.currentTimeMillis();
            long duration = timeEnd - timeStart;
            System.out.println("millisecs: " + duration);
        }

        int[] expNums = { 1, 10, 20 };
        System.out.println("==O(2^n)==");
        for (int n : expNums) {
            long timeStart = System.currentTimeMillis();
            bigO2NTime(n);
            long timeEnd = System.currentTimeMillis();
            long duration = timeEnd - timeStart;
            System.out.println("millisecs: " + duration);
        }

    }
}
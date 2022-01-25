import java.util.Scanner;

public class GcdRunner {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.println("GCD");
        System.out.println("Code by Raj Pabari");
        GCD gcd = new GCD(24, 9);
        System.out.println(gcd);
        System.out.println("result = " + gcd.findGCD());

        System.out.println("Gimme 2 ints: ");
        int int1 = scan.nextInt();
        int int2 = scan.nextInt();
        gcd = new GCD(int1, int2);
        System.out.println(gcd);
        System.out.println("result = " + gcd.findGCD());
        scan.close();
    }
}
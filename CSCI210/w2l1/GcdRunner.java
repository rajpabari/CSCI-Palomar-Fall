public class GcdRunner {
    public static void main(String[] args) {
        System.out.println("GCD");
        System.out.println("Code by Raj Pabari");
        GCD gcd = new GCD(24, 9);
        System.out.println(gcd);
        System.out.println("result = " + gcd.findGCD());

        gcd = new GCD(4, 2);
        System.out.println(gcd);
        System.out.println("result = " + gcd.findGCD());
    }
}
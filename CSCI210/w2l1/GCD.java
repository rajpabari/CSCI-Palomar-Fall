public class GCD {
    private int a;
    private int b;

    GCD(int a, int b) {
        this.a = a;
        this.b = b;
    }

    public String toString() {
        return "a = " + a + ", b = " + b;
    }

    public int findGCD() {
        int numLoops = 0;
        int remainder = a % b;
        while (remainder != 0) {
            numLoops++;
            a = b;
            b = remainder;
            remainder = a % b;
        }
        System.out.println("numLoops: " + numLoops);
        return b;
    }
}
import java.lang.Math;

public class Octal {

    private String input;
    private Decimal dec;

    public Octal(String in) {
        this.input = in;
        dec = new Decimal();
        dec.setValue(this.returnDec(input));
    }

    public String toString() {
        return "Oct: " + input;
    }

    public String displayDec() {
        return dec.toString();
    }

    private int returnDec(String octal) {
        int ans = 0;
        char current;
        int currentValue = 0;

        for (int i = octal.length() - 1; i >= 0; i--) {
            current = octal.charAt(i);
            currentValue = Character.getNumericValue(current);
            if (currentValue > 9) {
                System.out.println("Error converting input to octal");
                System.exit(1);
            }
            ans += (int) (currentValue * Math.pow(8, octal.length() - 1 - i));
        }
        return ans;
    }

    public String displayBin() {
        return dec.displayBin();
    }

    public String displayHex() {
        return dec.displayHex();
    }
}

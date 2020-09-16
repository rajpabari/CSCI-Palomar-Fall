import java.lang.Math;

public class Hex {

    private String input;
    private Decimal dec;

    public Hex(String in) {
        this.input = in;
        dec = new Decimal();
        dec.setValue(this.returnDec(input));
    }

    public String toString() {
        return "Hex: " + input;
    }

    public String displayDec() {
        return dec.toString();
    }

    private int returnDec(String binary) {
        int ans = 0;
        char current;
        int currentValue = 0;

        for (int i = binary.length() - 1; i >= 0; i--) {
            current = binary.charAt(i);
            if (current == 'a' || current == 'A') {
                currentValue = 10;
            } else if (current == 'b' || current == 'B') {
                currentValue = 11;
            } else if (current == 'c' || current == 'C') {
                currentValue = 12;
            } else if (current == 'd' || current == 'D') {
                currentValue = 13;
            } else if (current == 'e' || current == 'E') {
                currentValue = 14;
            } else if (current == 'f' || current == 'F') {
                currentValue = 15;
            } else {
                currentValue = Character.getNumericValue(current);
                if (currentValue > 9) {
                    System.out.println("Error converting input to hex");
                    System.exit(1);
                }
            }
            ans += (int) (currentValue * Math.pow(16, binary.length() - 1 - i));
        }
        return ans;

    }

    public String displayOct() {
        return dec.displayOct();
    }

    public String displayBin() {
        return dec.displayBin();
    }
}

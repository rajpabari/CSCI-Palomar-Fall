import java.lang.Math;

public class Binary {

    private String input;
    private Decimal dec;

    public Binary(String in) {
        this.input = in;
        dec = new Decimal();
        dec.setValue(this.returnDec(input));
    }

    public String toString() {
        return "Bin: " + input;
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
            currentValue = Character.getNumericValue(current);
            if (currentValue > 9) {
                System.out.println("Error converting input to binary");
                System.exit(1);
            }
            ans += (int) (currentValue * Math.pow(2, binary.length() - 1 - i));
        }
        return ans;
    }

    public String displayOct() {
        return dec.displayOct();
    }

    public String displayHex() {
        return dec.displayHex();
    }
}

public class Decimal {

    private int input;

    public Decimal() {
        input = 0;
    }

    public Decimal(String in) {
        try {
            this.input = Integer.parseInt(in);
        } catch (Exception e) {
            System.out.println("Error converting input to decimal");
            System.exit(1);
        }
    }

    public int setValue(int in) {
        this.input = in;
        return 0;
    }

    public String toString() {
        return "Dec: " + input;
    }

    public String displayOct() {
        return "Oct: " + Integer.toOctalString(input);
    }

    public String displayBin() {
        return "Bin: " + Integer.toBinaryString(input);
    }

    public String displayHex() {
        return "Hex: " + Integer.toHexString(input);
    }
}

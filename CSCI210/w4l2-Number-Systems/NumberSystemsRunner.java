public class NumberSystemsRunner {

    public static void usage() {
        System.out.println(
                "Usage Syntax\njava Main --input-[dec | oct | hex | bin] VALUE --output-[dec | oct | hex | bin]\nUsage Examples:\njava Main --input-dec 1234 --output-hex\njava Main --input-hex 4d2 --output-dec");
        System.exit(0);
    }

    public static void doCLIArgs(String[] args) {

        // one thing that I changed is that instead of making displayHex(),
        // displayDec(), etc. voids, I made them public String because it bugs me to
        // have objects print non-error messages

        if (args.length != 3)
            usage();
        else if (args[0].equals("--input-dec")) {
            Decimal dec = new Decimal(args[1]);
            System.out.println(dec);
            if (args[2].equals("--output-oct")) {
                System.out.println(dec.displayOct());
            } else if (args[2].equals("--output-hex")) {
                System.out.println(dec.displayHex());
            } else if (args[2].equals("--output-bin")) {
                System.out.println(dec.displayBin());
            } else {
                System.out.println("error parsing output type");
                System.exit(1);
            }
        } else if (args[0].equals("--input-oct")) {
            Octal oct = new Octal(args[1]);
            System.out.println(oct);
            if (args[2].equals("--output-dec")) {
                System.out.println(oct.displayDec());
            } else if (args[2].equals("--output-hex")) {
                System.out.println(oct.displayHex());
            } else if (args[2].equals("--output-bin")) {
                System.out.println(oct.displayBin());
            } else {
                System.out.println("error parsing output type");
                System.exit(1);
            }
        } else if (args[0].equals("--input-bin")) {
            Binary bin = new Binary(args[1]);
            System.out.println(bin);
            if (args[2].equals("--output-dec")) {
                System.out.println(bin.displayDec());
            } else if (args[2].equals("--output-hex")) {
                System.out.println(bin.displayHex());
            } else if (args[2].equals("--output-oct")) {
                System.out.println(bin.displayOct());
            } else {
                System.out.println("error parsing output type");
                System.exit(1);
            }
        } else if (args[0].equals("--input-hex")) {
            Hex hex = new Hex(args[1]);
            System.out.println(hex);
            if (args[2].equals("--output-dec")) {
                System.out.println(hex.displayDec());
            } else if (args[2].equals("--output-bin")) {
                System.out.println(hex.displayBin());
            } else if (args[2].equals("--output-oct")) {
                System.out.println(hex.displayOct());
            } else {
                System.out.println("error parsing output type");
                System.exit(1);
            }
        } else {
            System.out.println("error parsing input type");
            System.exit(1);
        }
    }

    public static void main(String[] args) {
        Welcome wel = new Welcome("Raj Pabari");
        System.out.println(wel.doWelcome());

        if (args.length == 0)
            usage();

        doCLIArgs(args);

        System.exit(0);
    }
}
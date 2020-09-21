public class ParenRunner {
    /*
     * private static int stackSize;
     * 
     * private static int getStackSize() { return stackSize; }
     * 
     * private static String push(char c) { stackSize++; return "push: stackSize = "
     * + stackSize; }
     * 
     * private static String pop(char c) { stackSize--; return "pop: stackSize = " +
     * stackSize; }
     */
    private static String title() {
        return "Correctly Parenthesized\nCode by Raj Pabari";
    }

    private static String usage() {
        return "Usage info\n" + "Enter a string to check\n" + "Example: java Main '(a+b)*((c+d)/(f+g))'\n"
                + "NOTE: be sure to use single quotes around the string\n";
    }

    public static void main(String[] args) {
        System.out.println(title());
        if (args.length == 0) {
            System.out.println(usage());
            System.exit(0);
        }
        CharStack charStack = new CharStack();

        char current;
        for (int i = 0; i < args[0].length(); i++) {
            current = args[0].charAt(i);
            if (current == '(') {
                System.out.println("Push " + current + " into stack");
                try {
                    charStack.push(current);
                } catch (Exception e) {
                    System.out.println(e);
                }
            } else if (current == ')')
                try {
                    System.out.println("Pop " + charStack.pop() + " from stack because " + current + " = current");
                } catch (Exception e) {
                    System.out.println(e);
                }
        }

        if (charStack.isEmpty())
            System.out.println("Valid");

        else
            System.out.println("Not Valid");

    }

}
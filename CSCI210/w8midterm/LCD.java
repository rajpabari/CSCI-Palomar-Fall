public class LCD {
    private char[] display;

    public LCD() {
        display = new char[16];
    }

    public void print(String message) {
        for (int i = 0; i < message.length(); i++) {
            try {
                display[i] = message.charAt(i);
                System.out.print(display[i]);
            } catch (IndexOutOfBoundsException e) {
                break;
            }
        }
        System.out.print("\n");
    }

}

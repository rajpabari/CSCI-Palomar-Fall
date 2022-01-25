import java.util.InputMismatchException;
import java.util.Scanner;

public class Keypad {

    public Keypad() {

    }

    public void handlePin(Scanner scan, LCDDisplay lcd) {
        lcd.askForPin(true);
        String x = "";
        while (x.trim().length() != 4) {
            if (!x.equals(""))
                lcd.askForPin(false);
            x = scan.next();
            try {
                if (Integer.parseInt(x) < 0) {
                    x = "bad";
                }
            } catch (NumberFormatException e) {
                x = "bad"; // makes it so the loop has to go again bc it's bad
            }
            if (x.equals(""))
                x = "also bad";
        }
    }

    public int getWithdrawAmount(Scanner scan, LCDDisplay lcd) {
        int ans = -10;
        do {
            if (ans > 0) {
                lcd.askForWithdraw(false);
            } else
                lcd.askForWithdraw(true);
            try {
                ans = Integer.parseInt(scan.next());
                scan.nextLine();
            } catch (NumberFormatException e) {
                ans = 2;
            }
            if (ans <= 0)
                ans = 1;
        } while (ans % 10 != 0);
        return ans;
    }
}

import java.util.Scanner;

public class CardReader {

    public CardReader() {
    }

    public void getInput(Scanner scan, LCDDisplay lcd) {
        lcd.askForCard();
        scan.nextLine();
    }
}

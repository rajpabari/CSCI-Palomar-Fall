import java.util.InputMismatchException;
import java.util.Scanner;

public class LCDDisplay {

    public LCDDisplay() {
        System.out.println("ATM project\nversion 0.0.1\n(C) Raj Inc\nCode by Raj Pabari");
    }

    public void displayWelcome() {
        System.out.println("\n-----\nWelcome to ATM");
    }

    public void askForPin(boolean isFirstTime) {
        if (isFirstTime)
            System.out.print("Type in 4 digit pin: ");
        else
            System.out.print("\nSorry, invalid PIN. Please type in 4 integer PIN: ");
    }

    public void askForCard() {
        System.out.print("Hit enter to put card in card reader: ");
    }

    public void askForWithdraw(boolean isFirstTime) {
        if (isFirstTime)
            System.out.print("How much do you want to withdraw? Must be a positive multiple of $10: ");
        else
            System.out.print("\nSorry, invalid withdrawal amount. Please type in positive multiple of $10: ");
    }

    public int getWithdrawAmount(Scanner scan) {
        int ans = -10;
        do {
            if (ans > 0) {
                System.out.print("\nSorry, invalid withdrawal amount. Please type in positive multiple of $10: ");
            } else
                System.out.print("How much do you want to withdraw? Must be a positive multiple of $10: ");
            try {
                ans = scan.nextInt();
            } catch (InputMismatchException e) {
                continue;
            }
            scan.nextLine();
            if (ans <= 0)
                ans = 1;
        } while (ans % 10 != 0);
        return ans;
    }

    public void displayWithdrawnBills(int ten, int twenty, int hundred) {
        System.out.println("Withdrawing $" + ((ten * 10) + (twenty * 20) + (hundred * 100)));
        System.out.println("Tens: " + ten + "\nTwentys: " + twenty + "\nHundreds: " + hundred);
    }

    public void displayThanks() {
        System.out.println("Thank you for using ATM");
    }

    public void waitTenSecs() {
        try {
            Thread.sleep(10000);
        } catch (InterruptedException e) {
            return;
        }
    }

}

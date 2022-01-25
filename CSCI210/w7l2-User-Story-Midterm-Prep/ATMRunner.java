import java.util.Scanner;

public class ATMRunner {
    /*
    Create an ATM Machine that matches the following User Story 
    •Display Startup Message 
    •title and version number and developer name at startup 
    •Run the ATM Machine 
    •User walks up to ATM Machine and sees Welcome Message  
    •Wait for insert of ATM card (that says press ENTER to begin) 
    •User does login process using 4-digit pin code 
    •User enters amount to withdraw in $10 increments 
    •Cash dispensed in a few bills as possible using $10, $20, and $100 bills 
    •A “Thank You” message at the end 
    •After 10 seconds display welcome message again
    */

    /*
    Stepwise refinement:
    ATM machine {
        initialize system
        -init lcd
        -init card reader
        -init keypad
        -init cash dispenser
        run atm
        -display startup info {
            title
            version
            copyright
            developer
        }
        -user i/o {
            display welcome msg
            wait for insert atm
            handle pin entry
            get amount to withdraw
            verify amount to withdraw
            withdraw
            display thank you
            wait 10 seconds
        }
    }
    */

    public static void main(String[] args) {
        LCDDisplay lcd = new LCDDisplay();
        CardReader cardReader = new CardReader();
        Keypad keypad = new Keypad();
        Dispenser dispenser = new Dispenser();
        Scanner scan = new Scanner(System.in);

        while (true) {
            lcd.displayWelcome();
            cardReader.getInput(scan, lcd);
            keypad.handlePin(scan, lcd);
            dispenser.withdraw(keypad.getWithdrawAmount(scan, lcd), lcd);
            lcd.displayThanks();
            lcd.waitTenSecs();
        }
    }
}

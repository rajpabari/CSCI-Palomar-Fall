public class Dispenser {

    public Dispenser() {

    }

    public void withdraw(int amount, LCDDisplay lcd) {
        int hundred = amount / 100;
        amount -= (amount / 100) * 100;
        int twenty = amount / 20;
        amount -= (amount / 20) * 20;
        int ten = amount / 10;
        amount -= (amount / 10) * 10;

        lcd.displayWithdrawnBills(ten, twenty, hundred);
    }
}

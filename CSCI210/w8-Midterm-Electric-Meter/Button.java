public class Button {
    private boolean buttonState; // false means not pressed, true means pressed

    public Button() {
        buttonState = false;
    }

    public Button(boolean buttonState) {
        this.buttonState = buttonState;
    }

    public Button(int buttonInt) {
        if (buttonInt == 0)
            this.buttonState = false;
        else
            this.buttonState = true;
    }

    public void pressButton() {
        buttonState = !buttonState;
    }

    public boolean getState() {
        return buttonState;
    }

    public String toString() {
        if (buttonState)
            return "Button IS pressed";
        else
            return "Button IS NOT pressed";
    }
}

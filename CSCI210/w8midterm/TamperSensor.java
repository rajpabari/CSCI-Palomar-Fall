public class TamperSensor {
    private boolean tamperSensorState; // false means off, true means on

    public TamperSensor() {
        tamperSensorState = true;
    }

    public TamperSensor(boolean tamperSensorState) {
        this.tamperSensorState = tamperSensorState;
    }

    public TamperSensor(int tamperInt) {
        if (tamperInt == 0)
            this.tamperSensorState = false;
        else
            this.tamperSensorState = true;
    }

    public void toggleState() {
        tamperSensorState = !tamperSensorState;
    }

    public boolean getState() {
        return tamperSensorState;
    }

    public String toString() {
        if (tamperSensorState)
            return "Tamper Sensor is ON";
        else
            return "Tamper Sensor is OFF";
    }
}

import java.lang.Math;

public class MetrologySensor {
    private double voltage;
    private double current;

    public MetrologySensor() {
        voltage = 0;
        current = 0;
    }

    public MetrologySensor(double voltage, double current) {
        this.voltage = voltage;
        this.current = current;
    }

    public void setVoltage(double volts) {
        voltage = volts;
    }

    public void setCurrent(double amps) {
        current = amps;
    }

    public double getVoltage() {
        return Math.round(voltage * 10) / 10.0;
    }

    public double getCurrent() {
        return Math.round(current * 10) / 10.0;
    }

    public String toString() {
        return "Voltage: " + getVoltage() + " Current: " + getCurrent();
    }
}

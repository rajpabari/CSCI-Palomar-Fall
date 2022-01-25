import java.lang.Math;

public class TemperatureSensor {
    int degreesCelsius;
    int degreesFahrenheit;

    public TemperatureSensor() {
        setTemperature(0, true);
    }

    public TemperatureSensor(int degrees, boolean isCelsius) {
        setTemperature(degrees, isCelsius);
    }

    public void setTemperature(int degrees, boolean isCelsius) {
        if (isCelsius) {
            degreesCelsius = degrees;
            degreesFahrenheit = (int) Math.round((degrees * 1.8) + 32);
        } else {
            degreesFahrenheit = degrees;
            degreesCelsius = (int) Math.round((degrees - 32) * (5.0 / 9.0));
        }
    }

    public int getTemperature(boolean isCelsius) {
        if (isCelsius)
            return degreesCelsius;
        else
            return degreesFahrenheit;
    }

    public String toString() {
        return "Temperature: " + degreesFahrenheit + "ºF " + degreesCelsius + "ºC";
    }

}

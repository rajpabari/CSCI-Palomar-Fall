public class Meter {
    private MeterType m_meterType;
    private MeterPower m_meterPower;
    private int m_reading;

    public Meter(MeterType type, MeterPower power, int reading) {
        m_meterType = type;
        m_meterPower = power;
        m_reading = reading;
    }

    public String toString() {
        return "type: " + m_meterType + ", power: " + m_meterPower + ", reading: " + m_reading;
    }

}
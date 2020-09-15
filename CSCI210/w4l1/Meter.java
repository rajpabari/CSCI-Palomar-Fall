public class Meter {
    private MeterType m_meterType;
    private MeterPower m_meterPower;
    int reading;

    public Meter(MeterType type, MeterPower power, int reading) {
        m_meterType = type;
        m_meterPower = power;
        this.reading = reading;
    }

}
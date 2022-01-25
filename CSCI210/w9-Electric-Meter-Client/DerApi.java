import java.util.Random;

public class DerApi {
    private DerDeviceType deviceType;
    private Random rand;
    private byte[] signature;
    private String id;

    public DerApi(DerDeviceType device, String deviceID) {
        id = deviceID;
        setDeviceType(device);
        rand = new Random();
        signature = new byte[100]; // maxLength is 100
        rand.nextBytes(signature);
    }

    public DerApi(DerDeviceType device) {
        this(device, "000");
    }

    public DerApi(String id) {
        this(DerDeviceType.DEFAULT, id);
    }

    public DerApi() {
        this(DerDeviceType.DEFAULT);
    }

    public void setDeviceType(DerDeviceType device) {
        deviceType = device;
    }

    public DerDeviceType getDeviceType() {
        return deviceType;
    }

    public double getWattHoursDelivered() {
        return rand.nextDouble();
    }

    public double getWattHoursReceived() {
        return rand.nextDouble();
    }

    public byte[] signData(byte[] dataToSign) {
        byte[] newData = new byte[dataToSign.length + signature.length];
        for (int i = 0; i < dataToSign.length; i++) {
            newData[i] = dataToSign[i];
        }
        for (int i = 0; i < signature.length; i++) {
            newData[i + dataToSign.length] = dataToSign[i];
        }
        return newData;
    }

    public byte[] getCert(CertType cert) {
        return cert.name().getBytes();
    }

    //this is the first 20 bytes of the certificate according to IEEE 2030.5 docs
    public String[] getLFDIs() {
        String[] LFDIs = new String[100];
        for (int i = 0; i < signature.length; i++) {
            LFDIs[i] = String.valueOf(signature[i]);
        }
        return LFDIs;
    }

    public String getIpAddr() {
        return "192.168.1.1";
    }

    public String getID() {
        return id;
    }
}
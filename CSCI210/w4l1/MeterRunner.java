import java.util.ArrayList;

public class MeterRunner {

    private static boolean m_verbose;
    private static boolean m_json;

    private static boolean m_lookingForMeterType;
    private static int m_meterTypeRunner;

    private static boolean m_lookingForMeterPower;
    private static int m_meterPowerRunner;

    private static boolean m_lookingForMeterReading;
    private static int m_meterReadingRunner;

    private static void usage() {
        System.out.println("Usage Info:");
        System.out.println("--version");
        System.out.println("--verbose");
        System.out.println("--json");
        System.out.println("--meter");
    }

    private static void version() {
        System.out.println("Version 0.0.0");
    }

    // CLI = command line interface
    private static void doCLIArgs(String[] args, ArrayList<Meter> array) {
        System.out.println("args.length = " + args.length);
        for (String s : args) {
            // System.out.println(s);
            // parse command-line args

            if (s.equals("--version")) {
                version();
                System.exit(42);
            }
            if (s.equals("--verbose")) {
                m_verbose = true;
                System.out.println("Running in verbose mode");
            } else if (s.equals("--json")) {
                m_json = true;
            } else if (s.equals("--meter")) {
                m_lookingForMeterType = true;

            } else if (m_lookingForMeterType) {
                // find the meter type
                String[] meterTypes = { "ELECTRIC", "GAS", "WATER" };
                for (int i = 0; i < meterTypes.length; i++) {
                    if (meterTypes[i].equals(s)) {
                        m_meterTypeRunner = i;
                        m_lookingForMeterType = false;
                        m_lookingForMeterPower = true;
                        break;
                    }
                }
                if (!m_lookingForMeterPower) {
                    System.out.println("Parse error on meter type");
                    System.exit(1);
                }
            } else if (m_lookingForMeterPower) {
                String[] meterPowers = { "MAINS", "BATTERY" };
                for (int i = 0; i < meterPowers.length; i++) {
                    if (meterPowers[i].equals(s)) {
                        m_meterPowerRunner = i;
                        m_lookingForMeterPower = false;
                        m_lookingForMeterReading = true;
                        break;
                    }
                }
                if (!m_lookingForMeterReading) {
                    System.out.println("Parse error on meter power");
                    System.exit(2);
                }
            } else if (m_lookingForMeterReading) {
                m_meterReadingRunner = Integer.parseInt(s);
                m_lookingForMeterReading = false;
                Meter m = new Meter(MeterType.values()[m_meterTypeRunner], MeterPower.values()[m_meterPowerRunner],
                        m_meterReadingRunner);
                array.add(m);
            } else {
                usage();
                System.exit(43);
            }
        }

    }

    private static ArrayList<Meter> createMeters() {
        Meter m = new Meter(MeterType.ELECTRIC, MeterPower.MAINS, 0);
        ArrayList<Meter> array = new ArrayList<Meter>();
        array.add(m);
        array.add(new Meter(MeterType.GAS, MeterPower.BATTERY, 0));
        return array;
    }

    public static void main(String[] args) {

        // Meter testing = new Meter(MeterType.ELECTRIC, MeterPower.BATTERY, 100);
        // System.out.println(testing);
        System.out.println("Meter tool");
        System.out.println("Code by Raj Pabari");

        if (args.length == 0) {
            usage();
            return;
        }

        // version 1: ArrayList<Meter> meterArray = createMeters();
        ArrayList<Meter> meterArray = new ArrayList<Meter>();
        doCLIArgs(args, meterArray);
        System.out.println("Meter Array");
        for (Meter m : meterArray) {
            System.out.println(m);
        }
    }
}

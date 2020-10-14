import java.util.List;

public class ElectricMeter {
    private FrontPanel frontPanel;
    private LCD lcd;
    private Button button;
    private TamperSensor tamper;
    private MetrologySensor met;
    private TemperatureSensor temp;
    private AccelerometerSensor accel;
    private int[] durations;
    private int durationIndex;
    private int totalDuration;
    private String[] header;

    public ElectricMeter(List<String> configFile, List<String> simFile) throws NoSuchFieldException {
        header = simFile.get(0).strip().split(",");
        String[] initialStates = simFile.get(1).strip().split(",");
        frontPanel = new FrontPanel(configFile);
        lcd = new LCD();
        accel = new AccelerometerSensor();
        met = new MetrologySensor();
        button = new Button();
        tamper = new TamperSensor();
        temp = new TemperatureSensor();
        durations = new int[simFile.size() - 1];
        for (int x = 0; x < header.length; x++) {
            if (header[x].strip().equals("seconds")) {
                durationIndex = x;
                for (int i = 0; i < durations.length; i++) {
                    durations[i] = Integer.parseInt(simFile.get(i + 1).strip().split(",")[durationIndex].strip());
                }
                break;
            }
        }
        totalDuration = durations[0];

        System.out.println("Front Panel Info");
        System.out.println(frontPanel);
        System.out.println("\nInitial Simulation Values");
        setValues(initialStates);
    }

    public void doSimulation(List<String> simFile) throws NoSuchFieldException {
        for (int i = 2; i < simFile.size(); i++) {
            totalDuration += durations[i - 1];
            if (totalDuration > 60) {
                System.out.println("Simulation over, 60-second time limit reached.");
                return;
            }
            System.out.println("Simulation Round #" + (i - 1));
            setValues(simFile.get(i).strip().split(","));
        }
    }

    public void setValues(String[] line) throws NoSuchFieldException {
        for (int i = 0; i < line.length; i++) {
            switch (header[i].strip()) {
                case "seconds": {
                    break;
                }
                case "button": {
                    if ((Integer.parseInt(line[i].strip()) == 1 && !button.getState())
                            || (Integer.parseInt(line[i].strip()) != 1 && button.getState()))
                        button.pressButton();
                    break;
                }
                case "tamper": {
                    if ((Integer.parseInt(line[i].strip()) == 1 && !tamper.getState())
                            || (Integer.parseInt(line[i].strip()) != 1 && tamper.getState()))
                        tamper.toggleState();
                    break;
                }
                case "volts": {
                    met.setVoltage(Double.parseDouble(line[i].strip()));
                    break;
                }
                case "amps": {
                    met.setCurrent(Double.parseDouble(line[i].strip()));
                    break;
                }
                case "tempc": {
                    temp.setTemperature(Integer.parseInt(line[i].strip()), true);
                    break;
                }
                case "tempf": {
                    temp.setTemperature(Integer.parseInt(line[i].strip()), false);
                    break;
                }
                default:
                    throw new NoSuchFieldException("Unsupported header type: " + header[i].strip());
            }
        }
        System.out.println(toString());

        // in real life this may be flashing or sliding across the screen
        System.out.println("--Begin LCD Displays--");
        lcd.print("Voltage: " + met.getVoltage());
        lcd.print("Current: " + met.getCurrent());
        System.out.println("--End LCD Displays--\n");
    }

    public String toString() {
        String str = "Total Duration: " + totalDuration + " secs";
        str += ", " + button.toString();
        str += ", " + tamper.toString();
        str += "\n" + met.toString();
        str += ", " + temp.toString();
        str += ", " + accel.toString();
        return str;
    }
}

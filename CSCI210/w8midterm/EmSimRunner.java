import java.nio.file.Files;
import java.nio.file.Paths;
import java.io.IOException;
import java.util.List;

class EmSimRunner {
    private static String CONFIGFILEPATH = "./CSCI210/w8midterm/emsim.config";
    private static String SIMFILEPATH = "./CSCI210/w8midterm/emsim.csv";

    public static void info() {
        System.out.println("Code by Raj Pabari");
        System.out.println("Electric Meter Simulator");
        System.out.println("version 1.0.1");
    }

    public static void main(String[] args) {
        info();
        try {
            List<String> configFile = Files.readAllLines(Paths.get(CONFIGFILEPATH));
            List<String> simFile = Files.readAllLines(Paths.get(SIMFILEPATH));
            System.out.println("header line: " + simFile.get(0) + "\n");
            try {
                ElectricMeter electricMeter = new ElectricMeter(configFile, simFile);
                electricMeter.doSimulation(simFile);
            } catch (NoSuchFieldException e) {
                System.out.println(e);
                System.exit(1);
            }
        } catch (IOException e) {
            System.out.println(e);
            System.exit(1);
        }
    }
}
import java.nio.file.Files;
import java.nio.file.Paths;
import java.io.IOException;
import java.io.File;
import java.util.List;

class EmSimRunner {
    private static String CONFIGFILEPATH = "./CSCI210/w8midterm/emsim.config";

    public static void info() {
        System.out.println("Code by Raj Pabari");
        System.out.println("Electric Meter Simulator");
        System.out.println("version 1.0.1");
    }

    public static void main(String[] args) {
        info();
        try {
            List<String> file = Files.readAllLines(Paths.get(CONFIGFILEPATH));
            FrontPanel frontPanel = new FrontPanel(file);

        } catch (IOException e) {
            System.out.println(e.getStackTrace());
            System.exit(1);
        }
    }
}
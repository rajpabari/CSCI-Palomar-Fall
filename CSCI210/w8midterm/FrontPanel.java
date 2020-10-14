import java.util.List;

public class FrontPanel {

    private String model;
    private int voltage;
    private int hertz;

    public FrontPanel(List<String> file) {
        //added whitespace handling
        String[] arr;
        for (int i = 0; i < file.size(); i++) {
            switch (i) {
                case 0:
                    arr = file.get(i).trim().split(" ");
                    model = arr[arr.length - 1];
                    break;
                case 1:
                    arr = file.get(i).trim().split(" ");
                    voltage = Integer.parseInt(arr[arr.length - 1]);
                    break;
                case 2:
                    arr = file.get(i).trim().split(" ");
                    hertz = Integer.parseInt(arr[arr.length - 1]);
                    break;
            }
        }
    }

    public String toString() {
        return "Model: " + model + ", Voltage: " + voltage + ", Hertz: " + hertz;
    }
}

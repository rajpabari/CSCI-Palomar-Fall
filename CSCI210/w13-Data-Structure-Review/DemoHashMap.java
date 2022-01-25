
//this data structure is analogous to python dictionary
import java.util.HashMap;

public class DemoHashMap {
    private HashMap<String, String> capitalCities;

    public DemoHashMap() {
        capitalCities = new HashMap<String, String>();
    }

    public void doStringDemo() {
        capitalCities.put("England", "London");
        capitalCities.put("Germany", "Berlin");
        capitalCities.put("Norway", "Oslo");
        capitalCities.put("USA", "Washington DC");
        System.out.println(capitalCities);
        System.out.println("Capital City of England: " + capitalCities.get("England"));

        // Print keys and values
        for (String i : capitalCities.keySet()) {
            System.out.println("key: " + i + " value: " + capitalCities.get(i));
        }
    }
}
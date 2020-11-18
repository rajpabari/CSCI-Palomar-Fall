import java.util.ArrayList;
import java.util.Collections;

class DemoArrayList {
    private ArrayList<String> list;

    public DemoArrayList() {
        list = new ArrayList<String>();
    }

    public void doStringDemo() {
        list.add("Volvo");
        list.add("BMW");
        list.add("Ford");
        list.add("Mazda");
        for (String i : list) {
            System.out.println(i);
        }
        System.out.println("Sorted ArrayList:");
        Collections.sort(list);
        for (String i : list) {
            System.out.println(i);
        }
    }
}
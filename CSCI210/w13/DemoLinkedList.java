import java.util.LinkedList;
import java.util.Collections;

public class DemoLinkedList {
    private LinkedList<String> list;

    public DemoLinkedList() {
        list = new LinkedList<String>();
    }

    public void doStringDemo() {
        System.out.println("Unsorted LinkedList:");
        list.addFirst("Volvo");
        list.addLast("Ford");
        list.addLast("BMW");
        list.addFirst("Mazda");
        for (String i : list) {
            System.out.println(i);
        }
        System.out.println("Sorted LinkedList:");
        Collections.sort(list);
        for (String i : list) {
            System.out.println(i);
        }
    }
}

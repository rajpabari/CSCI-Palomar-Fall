import java.util.LinkedList;
import java.util.ListIterator;
import java.util.NoSuchElementException;

public class LinkedListSample {

    public static void main(String[] args) {
        System.out.println("Linked List Intro Code Sample\nCode by Raj Pabari");

        LinkedList<String> colors = new LinkedList<String>();
        System.out.println(colors);

        colors.addFirst("red");
        System.out.println(colors);

        colors.addLast("green");
        System.out.println(colors);

        System.out.println(colors.getFirst());
        System.out.println(colors.getLast());

        ListIterator<String> iterator = colors.listIterator();
        while (iterator.hasNext()) {
            System.out.println(iterator.next());
        }

        try {
            iterator.next();
        }

        catch (NoSuchElementException e) {
            System.out.println(e);
        }
    }

}

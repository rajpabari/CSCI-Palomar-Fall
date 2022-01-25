import java.util.LinkedList;

public class LinkedListQueue {
    private LinkedList<Object> list;

    public LinkedListQueue() {
        list = new LinkedList<Object>();
    }

    public void add(Object o) {
        list.addLast(o);
    }

    public Object remove() {
        return list.removeFirst();
    }

    public int size() {
        return list.size();
    }
}

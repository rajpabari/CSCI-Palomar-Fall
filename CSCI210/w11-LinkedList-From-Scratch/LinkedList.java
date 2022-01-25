import java.util.NoSuchElementException;

class ListNode<T> {
    protected T data;
    protected ListNode<T> nextNode;

    protected ListNode(T thisElement, ListNode<T> node) {
        data = thisElement;
        nextNode = node;
    }

    protected ListNode(T element) {
        this(element, null);
    }

    /*protected T getData() {
        return data;
    }
    
    protected ListNode<T> getNext() {
        return nextNode;
    }*/
}

public class LinkedList<T> {
    private ListNode<T> firstNode;
    private ListNode<T> lastNode;

    public boolean isEmpty() {
        return firstNode == null;
    }

    public void insertAtFront(T item) {
        if (isEmpty()) {
            firstNode = lastNode = new ListNode<T>(item);
        } else {
            firstNode = new ListNode<T>(item, firstNode);
        }
    }

    public void insertAtBack(T item) {
        if (isEmpty()) {
            firstNode = lastNode = new ListNode<T>(item);
        } else {
            ListNode<T> newLastNode = new ListNode<T>(item);
            lastNode.nextNode = newLastNode;
            lastNode = newLastNode;
        }
    }

    public T removeFromFront() throws NoSuchElementException {
        if (isEmpty())
            throw new NoSuchElementException("LinkedList is empty dude!");
        T toReturn = firstNode.data;
        if (firstNode == lastNode) {
            firstNode = lastNode = null;
        } else {
            firstNode = firstNode.nextNode;
        }
        return toReturn;
    }

    //precondition: it's not empty or size 1
    private ListNode<T> getSecondLastNode() {
        ListNode<T> currentNode = firstNode;
        while (currentNode.nextNode.nextNode != null) {
            currentNode = currentNode.nextNode;
        }
        return currentNode;
    }

    public T removeFromBack() throws NoSuchElementException {
        if (isEmpty())
            throw new NoSuchElementException("LinkedList is empty dude!");
        T toReturn = lastNode.data;
        if (firstNode == lastNode) {
            firstNode = lastNode = null;
        } else {
            lastNode = getSecondLastNode();
            lastNode.nextNode = null;
        }
        return toReturn;
    }

    public String toString() {
        String ans = "[";
        if (isEmpty())
            return ans + "]";
        ListNode<T> currentNode = firstNode;
        while (currentNode.nextNode != null) {
            ans += currentNode.data + ", ";
            currentNode = currentNode.nextNode;
        }
        return ans + currentNode.data + "]";
    }
}
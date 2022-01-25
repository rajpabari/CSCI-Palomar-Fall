public class LinkedListQueueRunner {
    public static void main(String[] args) {
        System.out.println("Linked List Queue Code Sample\nCode by Raj Pabari");

        LinkedListQueue queue = new LinkedListQueue();

        queue.add("red");
        queue.add("green");
        queue.add("blue");

        System.out.println("size before removing: " + queue.size());

        System.out.println(queue.remove());
        System.out.println("size after removing: " + queue.size());

    }
}

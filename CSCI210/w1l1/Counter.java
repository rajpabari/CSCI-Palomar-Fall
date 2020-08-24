public class Counter {
    private int count;

    Counter() {
        System.out.println("Counter()");
    }

    void increment() {
        count++;
    }

    int getCount() {
        return count;
    }

    void setCount(int count) {
        this.count = count;
    }

}
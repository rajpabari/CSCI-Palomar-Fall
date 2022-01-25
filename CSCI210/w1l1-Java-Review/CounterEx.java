public class CounterEx extends Counter {
    CounterEx() {
        System.out.println("CounterEx()");
    }

    void decrement() {
        int count = getCount();
        count--;
        setCount(count);
    }

}
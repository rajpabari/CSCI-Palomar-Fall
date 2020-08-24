class Main {
    public static void main(String[] args) {
        System.out.println("Hello world!");
        System.out.printf("Code by Raj Pabari%n");

        Counter counter = new Counter();
        System.out.println("counter: " + counter.toString());
        System.out.println("counter: " + counter);

        counter.increment();
        counter.increment();
        System.out.printf("count: %d%n", counter.getCount());

        Counter counter2 = new Counter();
        counter2.setCount(42);
        System.out.println("counter2: " + counter2.getCount());

        CounterEx counterEx = new CounterEx();
        System.out.println("counterEx: " + counterEx);
        counterEx.increment();
        System.out.println("counterEx: " + counterEx.getCount());

        counterEx.decrement();
        System.out.println("counterEx: " + counterEx.getCount());

        System.out.println("All done!");
    }
}
public class CharStack {
    private char[] item;
    private int top;
    private int size;

    public CharStack() {
        size = 100;
        top = -1;
        item = new char[size];
    }

    public boolean isEmpty() {
        return top == -1;
    }

    public boolean isFull() {
        return top == item.length - 1;
    }

    public void clear() {
        top = -1;
    }

    public void push(char insert) throws Exception {
        if (isFull()) {
            throw new Exception("Stack Overflow");
        }
        item[++top] = insert;
    }

    public char pop() throws Exception {
        if (isFull()) {
            throw new Exception("Stack Empty");
        }
        return item[top--];
    }

}

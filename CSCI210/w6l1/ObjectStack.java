public class ObjectStack {
    private Object[] item;
    private int top;

    public ObjectStack() {
        item = new Square[1];
        top = -1;
    }

    public boolean isEmpty() {
        return top == -1;
    }

    public boolean isFull() {
        return top == item.length - 1;
    }

    public void clear() {
        item = new Object[1];
        top = -1;
    }

    public void push(Object o) {
        if (isFull()) {
            resize(2 * item.length);
        }
        item[++top] = o;

    }

    private void resize(int size) {
        Object[] temp = new Object[size];
        for (int i = 0; i <= top; i++) {
            temp[i] = item[i];
        }
        item = temp;
    }

    public Object pop() throws Exception {
        if (isEmpty()) {
            throw new Exception("Stack Underflow");
        }
        return item[top--];
    }

    public Object top() throws Exception {
        if (isEmpty()) {
            throw new Exception("Stack Underflow");
        }
        return item[top];
    }
}

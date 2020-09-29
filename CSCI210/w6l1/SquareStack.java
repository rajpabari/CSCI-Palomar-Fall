public class SquareStack {
    private Square[] item;
    private int top;

    public SquareStack() {
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
        item = new Square[1];
        top = -1;
    }

    public void push(Square square) {
        if (isFull()) {
            resize(2 * item.length);
        }
        item[++top] = square;

    }

    private void resize(int size) {
        Square[] temp = new Square[size];
        for (int i = 0; i <= top; i++) {
            temp[i] = item[i];
        }
        item = temp;
    }

    public Square pop() throws Exception {
        if (isEmpty()) {
            throw new Exception("Stack Underflow");
        }
        return item[top--];
    }

    public Square top() throws Exception {
        if (isEmpty()) {
            throw new Exception("Stack Underflow");
        }
        return item[top];
    }
}

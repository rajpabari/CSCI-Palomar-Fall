public class TreeNode<T> {
    private T value;
    private TreeNode<T> left;
    private TreeNode<T> right;

    public TreeNode() {
    }

    public TreeNode(T key) {
        this.value = key;
    }

    public TreeNode(TreeNode<T> other) {
        this.value = other.value;
        this.left = other.left;
        this.right = other.right;
    }

    public void setRight(TreeNode<T> right) {
        if (right != null) {
            this.right = right;
        } else {
            this.right = null;
        }
    }

    public void setLeft(TreeNode<T> left) {
        if (left != null) {
            this.left = left;
        } else {
            this.left = null;
        }
    }

    public TreeNode<T> getLeft() {
        return this.left;
    }

    public TreeNode<T> getRight() {
        return this.right;
    }

    public T getValue() {
        return this.value;
    }

    public String toString() {
        return value.toString();
    }
}

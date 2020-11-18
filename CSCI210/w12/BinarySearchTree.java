import java.util.Stack;
import java.util.Vector;

public class BinarySearchTree<T extends Comparable<T>> {

    private TreeNode<T> root;

    public BinarySearchTree() {

    }

    public BinarySearchTree(BinarySearchTree<T> another) {
        this.root = another.root;
    }

    //@return false if setting failed, true if successful
    public boolean setLeftChild(TreeNode<T> parent, TreeNode<T> left) {
        if (parent == null || parent.getLeft() != null)
            return false;
        parent.setLeft(left);
        return true;
    }

    //@return false if setting failed, true if successful
    public boolean setRightChild(TreeNode<T> parent, TreeNode<T> right) {
        if (parent == null || parent.getRight() != null)
            return false;
        parent.setRight(right);
        return true;
    }

    public TreeNode<T> getRoot() {
        return root;
    }

    //@return false if insertion failed, true if success
    public boolean insert(T value) {
        TreeNode<T> node = new TreeNode<T>(value);
        TreeNode<T> first, second;
        boolean isLeft = false;

        if (root == null) {
            root = node;
            return true;
        }

        first = root;
        second = root;
        while (second != null) {
            first = second;
            if (value.compareTo(first.getValue()) == 0) {
                return false; // handles the case where it's a duplicate by not adding into the BST
            } else if (value.compareTo(first.getValue()) < 0) {
                second = first.getLeft();
                isLeft = true;
            } else {
                second = first.getRight();
                isLeft = false;
            }
        }
        if (isLeft) {
            setLeftChild(first, node);
        } else {
            setRightChild(first, node);
        }

        return true;
    }

    //@return false if insertion failed, true if success
    public boolean insert(T[] values) {
        for (T i : values) {
            if (!insert(i))
                return false;
        }
        return true;
    }

    private TreeNode<T> search(TreeNode<T> tempRoot, T value) {
        TreeNode<T> temp;
        temp = tempRoot;

        if (temp.getValue().compareTo(value) > 0) {
            return search(temp.getLeft(), value);
        } else if (temp.getValue().compareTo(value) < 0) {
            return search(temp.getRight(), value);
        } else
            return temp;
    }

    public TreeNode<T> search(T value) {
        return search(root, value);
    }

    public void displayLowToHigh() {
        System.out.println(this.toString());
    }

    private TreeNode<T> deepClone(TreeNode<T> root) {
        if (root == null)
            return null;
        TreeNode<T> temp = new TreeNode<T>(root.getValue());
        temp.setLeft(deepClone(root.getLeft()));
        temp.setRight(deepClone(root.getRight()));
        return temp;
    }

    public String toString() {
        Stack<TreeNode<T>> nodes = new Stack<TreeNode<T>>();
        TreeNode<T> temp = deepClone(root);
        nodes.push(temp);
        String ans = "";
        TreeNode<T> top;

        while (!nodes.isEmpty()) {
            //if there is a node to the left
            if (nodes.peek().getLeft() != null) {
                //save the top node
                top = nodes.peek();
                // push the left child to the stack
                nodes.push(top.getLeft());
                // "cut off" the link from the parent to the left child
                top.setLeft(null);
            } else if (nodes.peek().getRight() != null) {
                top = nodes.pop();
                ans += top.toString() + " ";
                nodes.push(top.getRight());
                top.setRight(null);
            } else {
                ans += nodes.pop().toString() + " ";
            }
        }

        return ans;
    }
}
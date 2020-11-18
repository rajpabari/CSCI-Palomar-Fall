class Node {
    int key;
    Node left, right;

    public Node(int item) {
        key = item;
        left = right = null;
    }
}

class BinaryTree {
    // Root of Binary Tree 
    public Node root;

    // Constructors 
    public BinaryTree(int key) {
        root = new Node(key);
    }

    public BinaryTree() {
        root = null;
    }

}

public class DemoBinaryTree {
    private BinaryTree tree;

    public DemoBinaryTree() {
        tree = new BinaryTree();
    }

    public void doDemo() {
        /*create root*/
        tree.root = new Node(1);
        System.out.println("1 added");

        /* following is the tree after above statement 
        
          1 
        /   \ 
          null  null     */

        tree.root.left = new Node(2);
        System.out.println("2 added");
        tree.root.right = new Node(3);
        System.out.println("3 added");

        /* 2 and 3 become left and right children of 1 
           1 
         /   \ 
        2      3 
          /    \    /  \ 
        null null null null  */

        tree.root.left.left = new Node(4);
        System.out.println("4 added");
        /* 4 becomes left child of 2 
                1 
            /       \ 
           2          3 
         /   \       /  \ 
        4    null  null  null 
           /   \ 
          null null 
         */

    }
}

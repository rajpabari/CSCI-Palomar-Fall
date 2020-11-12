public class BSTRunner {
    public static void main(String[] args) {
        BinarySearchTree<Integer> bst = new BinarySearchTree<Integer>();
        Integer[] valuesToAdd = { 8, 3, 10, 1, 6, 14, 13, 4, 7 };
        bst.insert(valuesToAdd);
        bst.displayLowToHigh();
        System.out.println(bst);
        System.out.println(bst.search(13).getValue());
        System.out.println(bst.search(4).getValue());

        BinarySearchTree<String> bst2 = new BinarySearchTree<String>();
        String[] stringsToAdd = { "Charlie", "Henry", "Bob", "Joe", "Alan", "Pat", "Derek" };
        bst2.insert(stringsToAdd);
        bst2.displayLowToHigh();
        System.out.println(bst2);
        System.out.println(bst2.search("Henry").getValue());
        System.out.println(bst2.search("Pat").getValue());
        System.out.println(bst2.search("Jimmy").getValue()); // should throw a null pointer exception
    }
}

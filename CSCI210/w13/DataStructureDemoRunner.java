public class DataStructureDemoRunner {
    public static void main(String[] args) {
        System.out.println("--ArrayListDemo--");
        DemoArrayList demoArrayList = new DemoArrayList();
        demoArrayList.doStringDemo();

        System.out.println("--LinkedListDemo--");
        DemoLinkedList demoLinkedList = new DemoLinkedList();
        demoLinkedList.doStringDemo();

        System.out.println("--HashMapDemo--");
        DemoHashMap demoHashMap = new DemoHashMap();
        demoHashMap.doStringDemo();

        System.out.println("--BinaryTreeDemo--");
        DemoBinaryTree demoBinaryTree = new DemoBinaryTree();
        demoBinaryTree.doDemo();
    }
}
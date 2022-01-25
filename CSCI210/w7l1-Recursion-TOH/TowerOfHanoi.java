import java.util.Scanner;
import java.util.Stack;

public class TowerOfHanoi {
    private static Stack<Integer> a = new Stack<Integer>();
    private static Stack<Integer> b = new Stack<Integer>();
    private static Stack<Integer> c = new Stack<Integer>();

    public static void doTower(String start, String end, int numDisks) {
        Stack<Stack<Integer>> lastTwo = initEndTower(start, end);
        solveTower(initStartTower(start, numDisks), lastTwo.pop(), lastTwo.pop(), numDisks);
    }

    public static Stack<Integer> initStartTower(String start, int numDisks) {
        switch (start) {
            case "B":
                for (int i = numDisks; i >= 1; i--) {
                    b.push(i);
                }
                printStates();
                return b;
            case "C":
                for (int i = numDisks; i >= 1; i--) {
                    c.push(i);
                }
                printStates();
                return c;
            default:
            case "A":
                for (int i = numDisks; i >= 1; i--) {
                    a.push(i);
                }
                printStates();
                return a;
        }
    }

    public static Stack<Stack<Integer>> initEndTower(String start, String end) {
        Stack<Stack<Integer>> ans = new Stack<Stack<Integer>>();
        switch (end) {
            case "B":
                ans.push(b);
                if (start.equalsIgnoreCase("A"))
                    ans.push(c);
                else
                    ans.push(a);
                break;
            case "C":
                ans.push(c);
                if (start.equalsIgnoreCase("A"))
                    ans.push(b);
                else
                    ans.push(a);
                break;
            default:
            case "A":
                ans.push(a);
                if (start.equalsIgnoreCase("B"))
                    ans.push(c);
                else
                    ans.push(b);
        }
        return ans;
    }

    public static void solveTower(Stack<Integer> source, Stack<Integer> spare, Stack<Integer> target, int m) {
        if (!source.isEmpty() && m == 1) {
            target.push(source.pop());
            printStates();
            return;
        }
        //move m-1 disks to the spare rod
        solveTower(source, target, spare, m - 1);

        //move m disk from source to target
        target.push(source.pop());
        printStates();

        //move those m-1 disks from spare to target
        solveTower(spare, source, target, m - 1);
    }

    public static void printStates() {
        System.out.println("A: " + a + " B: " + b + " C: " + c);
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.println("Code by Raj Pabari\nTower of Hanoi Recursion");
        System.out.print("Enter starting rod (A, B, C): ");
        String start = scan.next();
        System.out.print("Enter ending rod (A, B, C): ");
        String end = scan.next();
        System.out.print("How many disks: ");
        int disks = scan.nextInt();
        while (start.equalsIgnoreCase(end)) {
            System.out.print("Ending rod cannot be same as starting rod.\nEnter ending rod (A, B, C): ");
            end = scan.next();
        }
        scan.close();

        doTower(start, end, disks);
    }
}
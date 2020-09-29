import java.nio.file.Files;
import java.nio.file.Paths;
import java.io.IOException;
import java.io.File;
import java.io.FileWriter;
import java.util.List;

//didn't look at the textbook code for this, so may be a bit different :)

public class MazeRunner {

    public static String title() {
        return "Maze Backtracker\n" + "Version 0.0.1\n" + "Code by Raj Pabari\n";
    }

    public static String usage() {
        return "Usage info\n" + "Enter maze filename\n" + "Example: java Main maze1.txt";
    }

    public static void main(String[] args) {
        System.out.println(title());
        if (args.length == 0) {
            System.out.println(usage());
            System.exit(0);
        }

        try {
            List<String> file = Files.readAllLines(Paths.get(args[0]));
            Maze maze = new Maze(file);
            //System.out.println(maze);

            while (!maze.hasWon()) {
                if (!maze.move()) {
                    System.out.println("No solution to maze");
                    System.exit(1);
                }
            }
            System.out.println(maze);
            File output = new File("./CSCI210/w6l1/mazeout.txt");
            FileWriter writer = new FileWriter("./CSCI210/w6l1/mazeout.txt");
            writer.write(maze.toString());
            writer.close();

        } catch (IOException e) {
            System.out.println(e);
            System.exit(1);
        }

    }
}

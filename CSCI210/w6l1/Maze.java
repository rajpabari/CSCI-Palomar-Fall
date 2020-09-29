import java.util.List;
import java.lang.Math;

//didn't look at the textbook code for this, so may be a bit different :)

public class Maze {

    List<String> file;
    char[][] maze;
    int sRow;
    int sCol;
    //SquareStack squares;
    ObjectStack objects;
    boolean hasWon;

    public Maze(List<String> contents) {
        file = contents;
        sRow = -1;
        sCol = -1;
        hasWon = false;

        //squares = new SquareStack();
        objects = new ObjectStack();
        //make maze with an additional row and column for the border
        maze = new char[(file.size()) + 2][(file.get(0).trim().length() / 2) + 3];

        for (int i = 0; i < maze.length; i++) {
            for (int j = 0; j < maze[0].length; j++) {
                if (i == 0 || j == 0 || i == maze.length - 1 || j == maze[0].length - 1) {
                    maze[i][j] = '1';
                    continue;
                }
                maze[i][j] = file.get(i - 1).trim().charAt((j - 1) * 2);
                if (maze[i][j] == 'S' || maze[i][j] == 's') {
                    sRow = i;
                    sCol = j;
                }
            }
        }
    }

    //return false if failed, true if backtrack or success
    public boolean move() {
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if ((Math.abs(i) >= 1 && Math.abs(j) >= 1) || i == j)
                    continue;
                if (maze[sRow + i][sCol + j] == '0' || maze[sRow + i][sCol + j] == 'E') {
                    if (maze[sRow + i][sCol + j] == 'E')
                        hasWon = true;

                    maze[sRow][sCol] = 'X';
                    //squares.push(new Square(sRow, sCol));
                    objects.push(new Square(sRow, sCol));

                    sRow += i;
                    sCol += j;
                    maze[sRow][sCol] = 'S';
                    return true;
                }
            }
        }
        maze[sRow][sCol] = '-';
        Square prev = new Square(0, 0);
        try {
            //prev = squares.pop();
            prev = (Square) objects.pop();
        } catch (Exception e) {
            return false;
        }
        sRow = prev.getRow();
        sCol = prev.getCol();
        maze[sRow][sCol] = 'S';
        return true;
    }

    //return true if you won the maze, false if you didn't
    public boolean hasWon() {
        return hasWon;
    }

    public String toString() {
        String ans = "";

        //skip the border because they don't need to see that in the output
        for (int i = 1; i < maze.length - 1; i++) {
            for (int j = 1; j < maze[0].length - 1; j++) {
                if (maze[i][j] == '-') {
                    ans += "0 ";
                    continue;
                }
                ans += maze[i][j] + " ";
            }
            ans += "\n";
        }
        return ans;
    }
}

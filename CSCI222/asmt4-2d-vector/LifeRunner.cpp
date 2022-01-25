#include <iostream>
#include <vector>

using namespace std;

// Prints each value of the board using cout
// @param vector<vector<char> > board a 2D vector to print
// @param int currentGen the current generation of the board
// @return none
void outputBoard(const vector<vector<char> > board, int currentGen) {
  // output generation
  cout << "Generation " << currentGen << ":\n";

  // output each cell of board
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[0].size(); j++) {
      cout << board[i][j] << " ";
    }
    cout << "\n";
  }
}

// Generates the state of the cell in the given
// row and col for the next generation
// @param vector<vector<char> > searchBoard the board to search for neighbors in
// @param int currentRow the row of the "active" given cell
// @param int currentCol the column of the "active" given cell
// @return char the value of this cell in the next generation

char nextState(const vector<vector<char> > searchBoard, int currentRow,
               int currentCol) {

  int neighbors = 0;

  // a represents the increment for the rows
  // b represents the increment for the columns
  // goes from -1 to 1 because you need to check each adjacent
  // row and column including diagonals

  for (int a = -1; a <= 1; a++) {
    for (int b = -1; b <= 1; b++) {
      // if a is 0 and b is 0, you are looking at the current cell
      // it's not a neighbor to itself thus continue
      if (a == 0 && b == 0)
        continue;

      // prevent bounds errors
      if (((a + currentRow) < 0) || ((b + currentCol) < 0) ||
          ((a + currentRow) >= searchBoard.size()) ||
          ((b + currentCol) >= searchBoard[0].size()))
        continue;

      // if there is a full neighboring cell to the current,
      // increment the count of neighbors
      else if (searchBoard[a + currentRow][b + currentCol] == 'o')
        neighbors++;
    }
  }

  // if there are 3 neigbors, the cell should be filled
  if (neighbors == 3)
    return 'o';

  // if there are 2 neighbors, leave the cell alone
  else if (neighbors == 2)
    return searchBoard[currentRow][currentCol];

  // otherwise, there are >= 4 neigbors or <= 1 neighbor,
  // which means that this cell should be dead, so return -
  else
    return '-';
}

int main() {
  // let user initialize the board
  cout << "Welcome to the Game of Life.\nHow many rows?\n";
  int rows = 5;
  cin >> rows;
  cout << "How many columns?\n";
  int cols = 5;
  cin >> cols;
  cout << "How many generations?\n";
  int gens = 10;
  cin >> gens;

  // initialize board with user defined rows and cols
  vector<vector<char> > board(rows);
  for (int i = 0; i < rows; i++) {
    board[i] = vector<char>(cols);
    for (int j = 0; j < cols; j++) {
      board[i][j] = '-';
    }
  }

  // create nextBoard, will be useful later
  vector<vector<char> > nextBoard = board;

  // instruct user how to set values for each cell
  cout << "Input o for a filled square or - for an empty square\n";
  cout << "Input space-separated values to initialize the each row of the "
          "board:\n";
  cout << "For instance, - o - o - -\n";

  // handle user input
  for (int i = 0; i < rows; i++) {
    cout << "Row " << i + 1 << ": ";
    for (int j = 0; j < cols; j++) {
      cin >> board[i][j];
    }
  }

  // for each generation
  for (int x = 0; x < gens; x++) {
    // begin by printing the board
    outputBoard(board, x);

    // for each cell in the board
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < rows; j++) {

        // set the corresponding cell in the next generation's board
        // to the call of nextState on the current cell

        nextBoard[i][j] = nextState(board, i, j);

        // NOTE: nextBoard is necessary because without it, there could be
        // errors because neighbor count is supposed to be based on
        // the values in the previous generation
      }
    }

    // set board to be the nextBoard
    board = nextBoard;
  }

  // output the final generation of Life, computation is already done
  // but it's not outputted yet
  outputBoard(board, gens);

  return 0;
}
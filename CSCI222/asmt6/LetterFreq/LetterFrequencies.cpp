#include <fstream>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

// Display usage information to cout
// @param none
// @return none
void usage() {
  cout << "Input name of file in command line" << endl;
  cout << "Example: g++ LetterFrequencies.cpp communistManifesto.txt" << endl;
}

// Driver code
// @param int argc the number of arguments
// @param char *argv[] char* array representing the arguments passed in
// @return 0 for success, 1 or other for failure/error
int main(int argc, char *argv[]) {
  if (argc != 2) {
    usage();  // display usage info
    return 0; // exit program
  }
  vector<string> file; // raw input data from file
  ifstream infile;
  infile.open(argv[1]); // open the filename supplied
  string line;

  // while there are lines to read in the file
  while (getline(infile, line)) {
    // push those lines to the end of the vector
    file.push_back(line);
  }

  int counts[26];       // count in the file of each character
  int totalLetters = 0; // total letters in the file
  // temporary int representing ASCII value of current char
  int currentChar;
  // for each line in file
  for (int i = 0; i < file.size(); i++) {
    // for each character in that line
    for (int j = 0; j < file[i].length(); j++) {
      // current char is the character in position j of line i of file
      currentChar = file[i].c_str()[j];

      // if it's capital ASCII, make it lowercase
      if (currentChar >= 'A' && currentChar <= 'Z') {
        // make lowercase by adding 32
        currentChar += 32;
      }

      // if it's a letter of the alphabet
      if (currentChar >= 'a' && currentChar <= 'z') {
        // increment the corresponding array value
        counts[currentChar - 'a']++;
        // and the total number of letters
        totalLetters++;
      }
    }
  }

  cout << "LETTER FREQUENCIES: " << endl << endl;

  // output each frequency
  for (int i = 0; i < 26; i++) {
    // NOTE: (int)(round(((double)counts[i] / (double)totalLetters) * 100))
    // yields integer of rounded double of percent frequency
    // you want double precision and want rounded not floored for accuracy
    if ((int)(round(((double)counts[i] / (double)totalLetters) * 100)) < 1) {
      // if it's less than 1%
      cout << (char)(i + 'a') << ": "
           << "<1%, ";
    }
    // if it's more than 1%, display the percent
    else {
      cout << (char)(i + 'a') << ": "
           << ((int)round((((double)counts[i] / (double)totalLetters) * 100)))
           << "%, ";
    }

    // formatting by adding newline breaks
    if (i != 0 && i % 5 == 0) {
      cout << endl;
    }
  }
  return 0;
}
#include "Student79.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#define NUM_QUIZZES 10

using namespace std;

// Display usage information to cout
// @param none
// @return none
void usage() {
  cout << "Input name of file in command line" << endl;
  cout << "Example: clang++ StudentRunnerP7-9.cpp student7-9.txt" << endl;
}

int main(int argc, char *argv[]) {
  // if there isn't 1 argument (argv[0] is filename)
  if (argc != 2) {
    usage();  // display usage info
    return 0; // exit program
  }

  vector<string> data; // raw input data from file
  ifstream infile;
  infile.open(argv[1]); // open the filename supplied
  string line;

  // while there are lines to read in the file
  while (getline(infile, line)) {
    // push those lines to the end of the vector
    data.push_back(line);
  }

  Student79 currentStudent;
  string currentLine;
  int counter; // counter is made to tell if we are looking at firstName
               // (counter=0), lastName (counter=1), or grade (counter=2)
  size_t pos;
  string match;
  vector<Student79> students(data.size());
  vector<int> courseGrades(NUM_QUIZZES);

  for (int i = 0; i < data.size(); i++) {
    currentLine = data[i]; // current line of the file
    pos = 0;
    counter = 0;
    // while you can find a space and it's not equal to "no position"
    // function, space is the delimiter
    while ((pos = currentLine.find(" ")) != currentLine.npos) {
      // match is the substing between the beginning of line and delimiter index
      match = currentLine.substr(0, pos);

      if (counter == 0) { // input format: this is first name
        currentStudent.firstName = match;
      } else if (counter == 1) { // input format: this is last name
        currentStudent.lastName = match;
      }
      // input format: these are all quiz scores to add them to courseGrades
      else {
        courseGrades[counter - 2] = stoi(match);
      }

      // erase the string up to and including the delimiter
      currentLine.erase(0, pos + 1); // pos+1 because delimiter length is 1
      counter++;
    }
    // what's left is the last grade
    courseGrades[9] = stoi(currentLine);
    // set quiz grades in struct
    currentStudent.quizGrades = courseGrades;
    // initialize the letter grade corresponding to these quiz grades
    currentStudent.initGrade();

    // insert this student into the vector of students SORTED
    for (int i = 0; i < students.size(); i++) {
      // put our new student in the first empty spot if nothing else
      // this means that we've done the other checks on all of
      // the students in the vector and we've arrived at a blank space
      if (students[i].grade == "") {
        students[i] = currentStudent;
        break;
      }
      // A is a special case because it needs to go right at the front
      else if (currentStudent.grade == "A") {
        // move all of the students back one in the vector
        // this will vacate index 0 for the currentStudent
        for (int j = students.size() - 1; j >= 1; j--) {
          students[j] = students[j - 1];
        }
        // insert our currentStudent to be first in the class
        students[0] = currentStudent;
        break;
      }
      // for all other letter grades...
      // checking if it's a worse grade than the one before it
      // AND it's a better or same grade than the one after it
      // no bounds errors because if i=students.size()-1, students[i].grade must
      // be 0
      else if (currentStudent.grade > students[i].grade &&
               currentStudent.grade <= students[i + 1].grade) {
        // vacate cell i+1 for the current student by moving other students back
        for (int j = students.size() - 1; j >= i + 2; j--) {
          students[j] = students[j - 1];
        }
        // insert this current student
        students[i + 1] = currentStudent;
        break;
      }
    }
  }

  // print each student's information from sorted student vector
  for (int i = 0; i < students.size(); i++) {
    cout << "Name: " << students[i].firstName << " " << students[i].lastName
         << ", Grade: " << students[i].grade
         << ", Quiz Scores: " << students[i].getQuizScores() << endl;
  }
  return 0;
}
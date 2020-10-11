#ifndef STUDENT79_H
#define STUDENT79_H
#include <string>
#include <vector>

using namespace std;

struct Student79 {
  string firstName;
  string lastName;
  string grade;
  vector<int> quizGrades;

  // takes quizGrades and determines what the letter grade should be
  // @param none
  // @return none
  void initGrade();

  // return a string representation of the student's quiz scores
  // @param none
  // @return string containing space-separated student's quiz scores
  string getQuizScores();
};

#endif
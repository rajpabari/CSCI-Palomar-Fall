#include "Student79.h"

void Student79::initGrade() {
  // get total grade
  int total = 0;
  for (int i = 0; i < quizGrades.size(); i++) {
    total += quizGrades[i];
  }

  // assign letter grade from number grade
  if (total >= 90) {
    grade = "A";
  } else if (total >= 80) {
    grade = "B";
  } else if (total >= 70) {
    grade = "C";
  } else if (total >= 60) {
    grade = "D";
  } else
    grade = "F";
}

string Student79::getQuizScores() {
  // get total grade
  string ans = "";

  // add each quiz grade to string representation
  for (int i = 0; i < quizGrades.size(); i++) {
    ans += to_string(quizGrades[i]);
    ans += " ";
  }
  return ans;
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// forward declare the course struct to avoid circular dependency
struct Course;

struct Student {
  string name;              // name of student
  vector<Course *> courses; // courses they're enrolled in
};

struct Course {
  string courseName;                  // name of course
  vector<Student *> enrolledStudents; // students enrolled in the course
};

// enroll a student in a course
// @param Student *s student to enroll
// @param Course *c course to enroll student in
// @return none
void enroll(Student *s, Course *c) {
  // add student to course's enrolled students vector
  c->enrolledStudents.push_back(s);
  // add course to student's enrolled course vector
  s->courses.push_back(c);
}

// print course info
// @param Course *c course who's info should be printed
// @return none
void printCourse(Course *c) {
  cout << "Course Name: " << c->courseName << endl;
  cout << "Enrolled Students: ";
  // print each enrolled student in the course
  for (int i = 0; i < c->enrolledStudents.size(); i++) {
    cout << c->enrolledStudents[i]->name << ", ";
  }
  cout << "\n\n";
}

// print student's info
// @param Student *s student who's info should be printed
// @return none
void printStudent(Student *s) {
  cout << "Student Name: " << s->name << endl;
  cout << "Courses Taking: ";
  // print each course the student is enrolled in
  for (int i = 0; i < s->courses.size(); i++) {
    cout << s->courses[i]->courseName << ", ";
  }
  cout << "\n\n";
}

int main() {
  // make students
  Student john;
  john.name = "John Smith";
  Student jane;
  jane.name = "Jane Doe";
  Student billy;
  billy.name = "Billy Bob";
  Student jim;
  jim.name = "Jim Cramer";
  Student tony;
  tony.name = "Tony Hawk";

  // make courses
  Course bio;
  bio.courseName = "Biology";
  Course math;
  math.courseName = "Math";
  Course english;
  english.courseName = "English";

  // enroll students in courses
  enroll(&john, &bio);
  enroll(&jane, &bio);
  enroll(&tony, &bio);

  enroll(&billy, &math);
  enroll(&tony, &math);
  enroll(&jane, &math);

  enroll(&john, &english);
  enroll(&jim, &english);

  // print each student and their schedule
  cout << "STUDENTS: " << endl << endl;
  printStudent(&john);
  printStudent(&jane);
  printStudent(&billy);
  printStudent(&jim);
  printStudent(&tony);

  // print each course and their roster
  cout << "COURSES: " << endl << endl;
  printCourse(&bio);
  printCourse(&math);
  printCourse(&english);

  return 0;
}
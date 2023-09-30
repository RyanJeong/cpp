#include <iostream>
#include <string>

const int MAX_COURSES = 5; // A student can take up to 5 courses
const int MAX_STUDENTS = 40; // A course can have up to 40 students

class Course; // forward declaration

class Student {
 private:
  std::string name;
  Course* courses[MAX_COURSES] = {nullptr}; // List of courses taken by student

 public:
  Student(const std::string& n) : name(n) {}

  // Function to add a course. Can add up to 5 courses
  void addCourse(Course* course) {
    for (int i = 0; i < MAX_COURSES; ++i) {
      if (!courses[i]) {
        courses[i] = course;
        break;
      }
    }
  }
};

class Course {
 private:
  std::string title;
  Student* students[MAX_STUDENTS] = {nullptr}; // List of students taking this course

 public:
  Course(const std::string& t) : title(t) {}

  // Function to add a student. Can add up to 40 students
  void addStudent(Student* student) {
    for (int i = 0; i < MAX_STUDENTS; ++i) {
      if (!students[i]) {
        students[i] = student;
        student->addCourse(this); // Add this course to student's list as well
        break;
      }
    }
  }
};

int main() {
  Student students[10]; // Array of students, can expand as needed
  Course courses[10]; // Array of courses, can expand as needed

  students[0] = Student("John");
  courses[0] = Course("Math");

  courses[0].addStudent(&students[0]);

  return 0;
}


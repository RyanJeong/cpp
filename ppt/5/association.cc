/*
    Copyright 2023 Munseong Jeong <munseong.jeong@daejin.ac.kr>

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
    http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include <iostream>
#include <string>

class Course;  // forward declaration

class Student {
 private:
  static const int kMaxCourse = 5;
  std::string name_;
  Course* course_[kMaxCourse] = {nullptr};

 public:
  explicit Student(const std::string& n) : name_(n) {}

  // Function to add a course. Can add up to 5 courses
  void add_course(Course* course) {
    for (int i = 0; i < kMaxCourse; ++i) {
      if (course_[i])
        continue;
      course_[i] = course;
      break;
    }
  }
};

class Course {
 private:
  static const int kMaxStudent = 40;
  std::string title_;
  Student* student_[kMaxStudent] = {nullptr};

 public:
  explicit Course(const std::string& t) : title_(t) {}

  // Function to add a student. Can add up to 40 students
  void add_student(Student* student) {
    for (int i = 0; i < kMaxStudent; ++i) {
      if (student_[i])
        continue;
      student_[i] = student;
      student->add_course(this);  // Add this course to student's list as well
      break;
    }
  }
};

int main() {
  Student students("John");
  Course courses("Math");
  courses.add_student(&students);

  return 0;
}


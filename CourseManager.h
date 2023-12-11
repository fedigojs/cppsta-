#pragma once
#pragma once
#include <iostream>
#include <map>
#include <vector>
#include "Student.h"
#include "Teacher.h"

using namespace std;

class CourseManager {
public:
    void enrollStudentInCourse(const string& course, const Student& student) {
        // Проверка на повторную запись студента
        if (!isStudentEnrolledInCourse(course, student)) {
            courses[course].first.push_back(student);
        }
    }

    void assignTeacherToCourse(const string& course, const Teacher& teacher) {
        // Проверка на повторное назначение учителя
        if (!isTeacherAssignedToCourse(course, teacher)) {
            courses[course].second.push_back(teacher);
        }
    }

    void displayCourseParticipants(const string& course) {
        cout << "Курси: " << course << endl;
        cout << "Студенти: " << endl;
        for (const auto& student : courses[course].first) {
            cout << student.getFullName() << endl;
        }
        cout << "Вчителя: " << endl;
        for (const auto& teacher : courses[course].second) {
            cout << teacher.getFullName() << endl;
        }
    }

private:
    map<string, pair<vector<Student>, vector<Teacher>>> courses;

    bool isStudentEnrolledInCourse(const string& course, const Student& student) {
        auto& students = courses[course].first;
        return find_if(students.begin(), students.end(), [&student](const Student& s) {
            return s.getFullName() == student.getFullName();
            }) != students.end();
    }

    bool isTeacherAssignedToCourse(const string& course, const Teacher& teacher) {
        auto& teachers = courses[course].second;
        return find_if(teachers.begin(), teachers.end(), [&teacher](const Teacher& t) {
            return t.getFullName() == teacher.getFullName();
            }) != teachers.end();
    }
};

#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>
#include "Student.h"
#include "Teacher.h"

using namespace std;

class PersonManager {
public:
    PersonManager(const string& filename)
        : filename(filename) {}

    void addStudent(const Student& student) {
        students.push_back(student);
        savePersonToFile(student); // Сохранить информацию о студенте в файл
    }

    void addTeacher(const Teacher& teacher) {
        teachers.push_back(teacher);
        savePersonToFile(teacher); // Сохранить информацию об учителе в файл
    }

    void loadFromFile() {
        ifstream file(filename);
        if (file.is_open()) {
            students.clear();
            teachers.clear();

            string line;
            while (getline(file, line)) {
                if (line == "Student") {
                    Student student;
                    loadPersonFromFile(student, file);
                    students.push_back(student);
                }
                else if (line == "Teacher") {
                    Teacher teacher;
                    loadPersonFromFile(teacher, file);
                    teachers.push_back(teacher);
                }
            }

            file.close();
        }
        else {
            cerr << "Помилка відкриття файлу " << filename << endl;
        }
    }

private:
    string filename;
    vector<Student> students;
    vector<Teacher> teachers;

    template <typename T>
    void savePersonToFile(const T& person) {
        ofstream file(filename, ios::app);
        if (!file.is_open()) {
            cerr << "Помилка відкриття файлу " << filename << endl;
            return;
        }

        if constexpr (is_same_v<T, Student>) {
            file << "Student\n";
            file << "Номер группи: " << person.getGroupNumber() << "\n";
            file << "Номер Курсу: " << person.getCourseNumber() << "\n";
            file << "Спеціальність: " << person.getSpeciality() << "\n";
            file << "Стипендія: " << person.getScholarship() << "\n";
        }
        else if constexpr (is_same_v<T, Teacher>) {
            file << "Teacher\n";
            file << "Стаж: " << person.getWorkExperience() << "\n";
            file << "Предмет: " << person.getSubject() << "\n";
            file << "Зарплатня: " << person.getSalary() << "\n";
        }

        file << "Ім'я: " << person.getFullName() << "\n";
        file << "Вік: " << person.getAge() << "\n";
        file << "Сать: " << person.getGender() << "\n";
        file << "Адреса: " << person.getAdress() << "\n";
        file << "Роль: " << person.getRoles() << "\n";
        file << "Хоббі: ";
        for (const auto& hobby : person.getHobbies()) {
            file << hobby << ", ";
        }
        file << "\n--------------------------------\n";

        file.close();
    }


    template <typename T>
    void loadPersonFromFile(T& person, ifstream& file) {
        // Загрузка атрибутов из файла
       

        // Обработка специфических атрибутов для Student или Teacher
        if constexpr (is_same_v<T, Student>) {
            // Обработка атрибутов Student
        }
        else if constexpr (is_same_v<T, Teacher>) {
            // Обработка атрибутов Teacher
        }
    }

    map<string, string> parseName(const string& fullName) {
        istringstream iss(fullName);
        string lastName, firstName, patronymic;
        iss >> lastName >> firstName >> patronymic;

        return { {"lastName", lastName}, {"firstName", firstName}, {"patronymic", patronymic} };
    }

    vector<string> parseHobbies(const string& hobbiesStr) {
        vector<string> hobbies;
        istringstream iss(hobbiesStr);
        string hobby;
        while (getline(iss, hobby, ',')) {
            hobbies.push_back(hobby);
        }
        return hobbies;
    }
};

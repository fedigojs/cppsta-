#include "Human.h"
#include "Teacher.h"
#include "Student.h"

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype> 
#include <sstream> 
#include <fstream>
#include <limits>


using namespace std;

int main() {
    setlocale(LC_ALL, "uk_UA.utf8");

    int choice;
    vector<Human> humans; // Вектор для хранения информации о людях

    while (true) {
        // Выводим меню
        cout << "Меню:" << endl;
        cout << "1. Добавити студента" << endl;
        cout << "2. Добавити вчителя" << endl;
        cout << "3. Вивести інформацію про всіх" << endl;
        cout << "4. Вивести інформацію о вчителях" << endl;
        cout << "5. Вивести інформацію о студентах " << endl;
        cout << "6. Вийти з програми" << endl;
        cout << "Виберіть дію (1-6): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1:
        {
            // Добавление студента
            Human student;
            student.putInfoHuman(); // Заполнение информации о студенте
            student.setRoles("student"); // Установка роли студента
            humans.push_back(student); // Добавление в вектор
            cout << "Студент успішно доданий!" << endl;
        }
        break;
        case 2:
        {
            // Добавление учителя
            Human teacher;
            teacher.putInfoHuman(); // Заполнение информации об учителе
            teacher.setRoles("teacher"); // Установка роли учителя
            humans.push_back(teacher); // Добавление в вектор
            cout << "Вчитель успішно доданий!" << endl;
        }
        break;
      


        case 6:
            // Выход из программы
            cout << "Програму завершено." << endl;
            return 0;
        default:
            cout << "Неправильний вибір. Будь ласка, виберіть дію від 1 до 6."<< endl;
        }

        // Очищаем буфер ввода
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }



    return 0;
}
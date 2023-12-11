#pragma once

#include "Human.h"
#include <string>
#include <vector>


using namespace std;

class Teacher : public Human {
public:
    Teacher() : workExperience(0), subject(""), salary(0.0) {}

    Teacher(
        map<string, string> name, int age, string gender, string adress,
        string roles, vector<string> hobbies, int workExperience,
        string subject, double salary 
    ) : Human(name, age, gender, adress, roles, hobbies),
        workExperience(workExperience), subject(subject), salary(salary) {}

    ~Teacher(){}

    // Getters
    int getWorkExperience() const { return workExperience; }
    string getSubject() const { return subject; }
    double getSalary() const { return salary; }

    // Setters
    void setWorkExperience(int experience) {
        if (experience >= 0) {
            workExperience = experience;
        }
        else {
            cerr << "Не корректний стаж роботи: " << experience << endl;
        }
    }

    void setSubject(const string& newSubject) {
        subject = newSubject;
    }

    void setSalary(double newSalary) {
        if (newSalary >= 0.0) {
            salary = newSalary;
        }
        else {
            cerr << "Не корректна зарплятня: " << newSalary << endl;
        }
    }

    void putInfo() override {
        Human::putInfo();
        cout << "Введіть предмет викладача:"; getline(cin, subject);
        cout << "Введіть стаж роботи:"; cin >> workExperience;
        cout << "Введіть зарплату:"; cin >> salary;
        cin.ignore();
    }
    
    void printInfo() const override {
        Human::printInfo(); 
        cout << "Стаж роботи: " << workExperience << " років" << endl;
        cout << "Курс який веде викладач: " << subject << endl;
        cout << "Зарплатня: " << salary << " грн" << endl;
    }

private:
    int workExperience; 
    string subject;    
    double salary;    
};

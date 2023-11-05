#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <limits>

#include "Human.h"

using namespace std;


class Student : public Human {
public:
	Student() : groupNumber(""), courseNumber(""), speciality(""), scholarship(0.0), tokenRating(0.0) {}

	Student (
		map<string, string> name, int age, string gender, string adress, string roles, vector<string> hobbies,
		string groupNumber, string courseNumber, string speciality, double scholarship, double tokenRating
	) : Human(name, age, gender, adress, roles, hobbies), groupNumber(groupNumber), courseNumber(courseNumber), 
		speciality(speciality), scholarship(scholarship), tokenRating(tokenRating){}

	~Student(){}

	//Getter
	string getGroupNumber() const { return groupNumber; }
	string getCourseNumber() const { return courseNumber; }
	string getSpeciality() const { return speciality; }
	double getScholarship() const { return scholarship; }
	double getTokenRating() const { return tokenRating; }
	
	//Setter
	void setGroupNumber(const string& newGroupNumber) {
		groupNumber = newGroupNumber;
	}

	void setCourseNumber(const string& newCourseNumber){
		courseNumber = newCourseNumber;
	}

	void setSpeciality(const string& newSpeciality) {
		speciality = newSpeciality;
	}

	void setScholarship(double newScholarship) {
		scholarship = newScholarship;
	}

	void setTokenRating(double newTokenRating) {
		tokenRating = newTokenRating;
	}

	void putInfoStudent() {
		putInfoHuman();
		cout << "Введіть номер курсу: "; getline(cin, courseNumber);
		cout << "Введіть номер группи: "; getline(cin, groupNumber);
		cout << "Введіть спеціальність: "; getline(cin, speciality);
		cout << "Введіть розмір стипендії:"; cin >> scholarship;
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка потока ввода

	}


	void printInfoStudent() {
		printInfoHuman();
		cout << "Курс: " << courseNumber << endl;
		cout << "Номер группи: " << groupNumber << endl;
		cout << "Спеціальність: " << speciality << endl;
		cout << "Стипендія:" << scholarship << endl;
		cout << "Рейтінг:" << tokenRating << endl;
	}

private:
	string groupNumber;
	string courseNumber;
	string speciality;
	double scholarship;
	double tokenRating;
};
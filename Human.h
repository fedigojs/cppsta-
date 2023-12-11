#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype> 
#include <sstream> 
#include <fstream>

using namespace std;



class Human {
public:

	Human()
		: name({}), age(0), gender("не визначено"), adress(""), roles("не визначено"), hobbies({}) {
	}

	Human(map<string, string> name, int age, string gender, string adress, string roles, vector<string> hobbies) {
		setName(name);
		setAge(age);
		setGender(gender);
		setAdress(adress);
		setRoles(roles);
		setHobbies(hobbies);
	}


	virtual ~Human() {}

	// Getter
	string getFullName() const {
		string fullName;
		if (name.find("lastName") != name.end()) {
			fullName += name.at("lastName") + " ";
		}
		if (name.find("firstName") != name.end()) {
			fullName += name.at("firstName") + " ";
		}
		if (name.find("patronymic") != name.end()) {
			fullName += name.at("patronymic");
		}
		return fullName;
	}

	int getAge() const { return age; }
	string getGender() const { return gender; }
	string getAdress() const { return adress; }
	string getRoles() const { return roles; }
	vector<string> getHobbies() const { return hobbies; }

	//setter
	void setName(const map<string, string>& newName) {
		name = newName;
	}

	void setAge(const int newAge) {
		if (newAge > 16 && newAge < 70) {
			age = newAge;
		}
		else {
			cerr << " Невірно введен вік " << newAge << endl;
		}
	}

	void setGender(const string& newGender) {
		if (newGender == "чоловік" || newGender == "жінка") {
			gender = newGender;
		}
		else {
			cerr << "Не вірно введена стать: " << newGender << endl;
		}
	}

	void setAdress(const string& newAdress) {
		adress = newAdress;
	}

	void setRoles(const string& newRoles) {
			roles = newRoles;
	}
	void setHobbies(const vector<string>& newHobbies) {
		hobbies.insert(hobbies.end(), newHobbies.begin(), newHobbies.end());
	}

	virtual void putInfo() {
		string fullName, firstName, lastName, patronymic;
		int age;
		string gender, adress, role;
		vector<string> hobbies;

		cout << "Введіть прізвищє Імʼя Побатькові: ";
		getline(cin, fullName);
		istringstream fio(fullName);
		fio >> lastName >> firstName >> patronymic;

		cout << "Введіть вік: "; cin >> age;
		cin.ignore();
		cout << "Введіть стать (чоловік/жінка): "; getline(cin, gender);
		cout << "Введіть адресу: "; getline(cin, adress);
		string hobby;
		cout << "Введіть хоббі (відділіть їх комами): ";
		getline(cin, hobby);
		istringstream hobbiesStream(hobby);
		while (getline(hobbiesStream, hobby, ',')) {
			hobbies.push_back(hobby);
		}

		//инициализация значений
		setName({ {"firstName", firstName}, {"lastName", lastName}, {"patronymic", patronymic} });
		setAge(age);
		setGender(gender);
		setAdress(adress);
		setHobbies(hobbies);

	}


	virtual void printInfo() const {
		cout << "ПІБ: " << getFullName() << endl;
		cout << "Вік: " << age << endl;
		cout << "Стать: " << gender << endl;
		cout << "Адреса: " << adress << endl;
		cout << "Хоббі: ";
		for (const auto& hobby : hobbies) {
			cout << hobby << ", ";
		}
		cout << endl;
	}


private:
	map <string, string> name;
	int age;
	string gender;
	string adress;
	string roles;
	vector<string> hobbies;
	//static int currentID;  // Статическая переменная для хранения последнего ID
	//int id; // уникалный ІD для каждого обьекта

};
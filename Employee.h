#pragma once

#include"IE.h"

class Employee : public IE
{

private:
	int id;
	string name;
	string email;
	int accessLevel;

public:
	Employee();
	Employee(int id, string name, string email, int accessLevel);
	Employee(const Employee& e);
	~Employee();

	int getId();
	string getName();
	string getEmail();
	int getAccessLevel();

	void setId(int newId);
	void setName(string newName);
	void setEmail(string newEmail);
	void setAccessLevel(int newAccessLevel);

	Employee& operator=(const Employee& e);
	bool operator==(const Employee& e);

	friend istream& operator>>(istream& is, Employee& e);
	friend ostream& operator<<(ostream& os, const Employee& e);

	Employee* clone();
	void copy(IE* e);
	bool equals(IE* e);
	int compareTo(IE* e);
	string toString();
};
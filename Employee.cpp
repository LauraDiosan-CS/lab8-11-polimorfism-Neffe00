#include"Employee.h"

Employee::Employee()
{
	this->id = 0;
	this->name = "";
	this->email = "";
	this->accessLevel = 0;
}

Employee::Employee(int id, string name, string email, int accessLevel)
{
	this->id = id;
	this->name = name;
	this->email = email;
	this->accessLevel = accessLevel;
}

Employee::Employee(const Employee& e)
{
	this->id = e.id;
	this->name = e.name;
	this->email = e.email;
	this->accessLevel = e.accessLevel;
}

Employee::~Employee()
{}

int Employee::getId()
{
	return this->id;
}

string Employee::getName()
{
	return this->name;
}

string Employee::getEmail()
{
	return this->email;
}

int Employee::getAccessLevel()
{
	return this->accessLevel;
}

void Employee::setId(int newId)
{
	this->id = newId;
}

void Employee::setName(string newName)
{
	this->name = newName;
}

void Employee::setEmail(string newEmail)
{
	this->email = newEmail;
}

void Employee::setAccessLevel(int newAccessLevel)
{
	this->accessLevel = newAccessLevel;
}

Employee& Employee::operator=(const Employee& e)
{
	this->id = e.id;
	this->name = e.name;
	this->email = e.email;
	this->accessLevel = e.accessLevel;
	return *this;
}

bool Employee::operator==(const Employee& e)
{
	return
		this->id == e.id &&
		this->name == e.name &&
		this->email == e.email &&
		this->accessLevel == e.accessLevel;
}

istream& operator>>(istream& is, Employee& e)
{
	is >> e.id >> e.name >> e.email >> e.accessLevel;
	return is;
}

ostream& operator<<(ostream& os, const Employee& e)
{
	os << e.id << ' ' << e.name << ' ' << e.email << ' ' << e.accessLevel;
	return os;
}

Employee* Employee::clone()
{
	Employee* pe = new Employee;
	pe->id = this->id;
	pe->name = this->name;
	pe->email = this->email;
	pe->accessLevel = this->accessLevel;

	return pe;
}

void Employee::copy(IE* e)
{
	Employee* emp = (Employee*)e;
	this->id = emp->id;
	this->name = emp->name;
	this->email = emp->email;
	this->accessLevel = emp->accessLevel;
}

bool Employee::equals(IE* e)
{
	Employee* emp = (Employee*)e;
	return
		this->id == emp->id &&
		this->name == emp->name &&
		this->email == emp->email &&
		this->accessLevel == emp->accessLevel;
}

int Employee::compareTo(IE* e)
{
	Employee* emp = (Employee*)e;

	return this->accessLevel > emp->accessLevel;
}

string Employee::toString()
{
	string s = "";
	s = s + "Employee: ";
	s = s + to_string(this->id);
	s = s + " ";
	s = s + this->name;
	s = s + " ";
	s = s + this->email;
	s = s + " ";
	s = s + to_string(this->accessLevel);
	return s;
}

#include"Medicine.h"

Medicament::Medicament()
{
	this->id = 0;
	this->name = "";
	this->needRecepie = 0;
	this->stockQuantity = 0;
	this->producer = "";
}

Medicament::Medicament(int id, string name, int needRecepie, int stockQuantity, string producer)
{
	this->id = id;
	this->name = name;
	this->needRecepie = needRecepie;
	this->stockQuantity = stockQuantity;
	this->producer = producer;
}

Medicament::Medicament(const Medicament& m)
{
	this->id = m.id;
	this->name = m.name;
	this->needRecepie = m.needRecepie;
	this->stockQuantity = m.stockQuantity;
	this->producer = m.producer;
}

Medicament::~Medicament()
{}

int Medicament::getId()
{
	return this->id;
}

string Medicament::getName()
{
	return this->name;
}

int Medicament::getNeedRecepie()
{
	return this->needRecepie;
}

int Medicament::getStockQuantity()
{
	return this->stockQuantity;
}

string Medicament::getProducer()
{
	return this->producer;
}

void Medicament::setId(int newId)
{
	this->id = newId;
}

void Medicament::setName(string newName)
{
	this->name = newName;
}

void Medicament::setNeedRecepie(int needRecepie)
{
	this->needRecepie = needRecepie;
}

void Medicament::setStockQuantity(int stockQuantity)
{
	this->stockQuantity = stockQuantity;
}

void Medicament::setProducer(string producer)
{
	this->producer = producer;
}

Medicament& Medicament::operator=(const Medicament& m)
{
	this->id = m.id;
	this->name = m.name;
	this->needRecepie = m.needRecepie;
	this->stockQuantity = m.stockQuantity;
	this->producer = m.producer;
	return*this;
}

bool Medicament::operator==(const Medicament& m)
{
	return
		this->id == m.id &&
		this->name == m.name &&
		this->needRecepie == m.needRecepie &&
		this->stockQuantity == m.stockQuantity &&
		this->producer == m.producer;
}

bool Medicament::operator!=(const Medicament& m)
{
	return
		!(this->id == m.id &&
			this->name == m.name &&
			this->needRecepie == m.needRecepie &&
			this->stockQuantity == m.stockQuantity &&
			this->producer == m.producer);
}


istream& operator>>(istream& is, Medicament& m)
{
	is >> m.id >> m.name >> m.needRecepie >> m.stockQuantity >> m.producer;
	return is;
}

ostream& operator<<(ostream& os, const Medicament& m)
{
	os << m.id << ' ' << m.name << ' ' << m.needRecepie << ' ' << m.stockQuantity << ' ' << m.producer;
	return os;
}

/*
Medicament* Medicament::clone()
{
	Medicament* pm = new Medicament;
	pm->id = this->id;
	pm->name = this->name;
	pm->needRecepie = this->needRecepie;
	pm->stockQuantity = this->stockQuantity;
	pm->producer = this->producer;
	return pm;
}

void Medicament::copy(IE* e)
{
	Medicament* pm = (Medicament*)e;
	this->id = pm->id;
	this->name = pm->name;
	this->needRecepie = pm->needRecepie;
	this->stockQuantity = pm->stockQuantity;
	this->producer = pm->producer;
}

bool Medicament::equals(IE* e)
{
	Medicament* pm = (Medicament*)e;
	return
		this->id == pm->id &&
		this->name == pm->name &&
		this->needRecepie == pm->needRecepie &&
		this->stockQuantity == pm->stockQuantity &&
		this->producer == pm->producer;
}

int Medicament::compareTo(IE* e)
{
	Medicament* pm = (Medicament*)e;
	return
		this->stockQuantity > pm->stockQuantity;
}

string Medicament::toString()

{
	string s = "";
	s = s + "Medicament: ";
	s = s + to_string(this->id);
	s = s + " ";
	s = s + this->name;
	s = s + " ";
	s = s + to_string(this->needRecepie);
	s = s + " ";
	s = s + to_string(this->stockQuantity);
	s = s + " ";
	s = s + this->producer;
	return s;
}

*/
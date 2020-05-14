#pragma once

#include<iostream>
using namespace std;

class Medicament
{
private:
	int id;
	string name;
	int needRecepie;
	int stockQuantity;
	string producer;

public:
	Medicament();
	Medicament(int id, string name, int needRecepie, int stockQuantity, string producer);
	Medicament(const Medicament& m);
	~Medicament();

	int getId();
	string getName();
	int getNeedRecepie();
	int getStockQuantity();
	string getProducer();

	void setId(int newId);
	void setName(string newName);
	void setNeedRecepie(int needRecepie);
	void setStockQuantity(int stockQuantity);
	void setProducer(string producer);

	Medicament& operator=(const Medicament& m);
	bool operator==(const Medicament& m);
	bool operator!=(const Medicament& m);

	friend istream& operator>>(istream& is, Medicament& m);
	friend ostream& operator<<(ostream& os, const Medicament& m);
};
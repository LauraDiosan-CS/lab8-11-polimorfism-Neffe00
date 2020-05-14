#pragma once

#include"Repo.h"

#include<iostream>
using namespace std;

template <class T>
class RepoFile : public Repo<T>
{
private:
	char* fileNameIn;
	char* fileNameOut;

public:
	RepoFile();
	RepoFile(const char* fileNameIn, const char* fileNameOut);
	RepoFile(const RepoFile& r);
	~RepoFile();
	RepoFile& operator = (const RepoFile& r);

	void addElement(T element);
	void updateElement(int id, T newElement);
	void deleteElement(int id);

	void setFileNameIn(const char* fileNameIn);
	void setFileNameOut(const char* fileNameOut);

	void loadFromFile();
	void saveToFile();

	void add(T element)
	{
		Repo<T>::addElement(element);
	}

	vector<T> getAll()
	{
		return this->getElements();
	}

	void update(Medicament* m, Medicament& newM)
	{
		vector<Medicament> Medicines = this->getElements();
		vector<Medicament> ::iterator it;
		for (it = Medicines.begin(); it != Medicines.end(); it++)
			if (it->getId() == m->getId())
			{
				this->updateElement(it->getId(), newM);
				break;
			}

		//delete m;
		//m = new Medicament(newM);
	}

	void remove(int id)
	{
		this->deleteElement(id);
	}
};
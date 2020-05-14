#pragma once

#include"Repo.h"
#include"Repo.cpp"
#include"RepoFile.h"
#include"RepoFile.cpp"

class MedicineService
{
private:
	RepoFile<Medicament> repoM;

public:
	MedicineService();
	MedicineService(const RepoFile<Medicament>& repoM);
	MedicineService(const MedicineService& MedicineService);
	MedicineService& operator=(const MedicineService& MedicineService);
	~MedicineService();

	int getNoMedicines();
	void addMedicine(int id, string name, int needRecepie, int stockQuantity, string producer);
	Medicament getMedicine(int id);
	vector<Medicament> getMedicines();
	void updateMedicine(int id, int newId, string name, int needRecepie, int stockQuantity, string producer);
	void deleteMedicine(int id);

	void add(const Medicament& m)
	{
		repoM.addElement(m);
	}

	vector<Medicament> getAll()
	{
		return repoM.getElements();
	}

	vector<Medicament> search(string namePart)
	{
		vector<Medicament> returnVector ;

		vector<Medicament> Medicines = this->getMedicines();
		vector<Medicament> ::iterator it;
		for (it = Medicines.begin(); it != Medicines.end(); it++)
			if (it->getName().find(namePart) != string::npos)
				returnVector.push_back(*it);
		
		return returnVector;
	}

	void update(Medicament* m, Medicament& newM)
	{	
		vector<Medicament> Medicines = this->getMedicines();
		vector<Medicament> ::iterator it;
		for (it = Medicines.begin(); it != Medicines.end(); it++)
			if ( it->getId() == m->getId() )
			{
				this->repoM.updateElement(it->getId(), newM);
				break;
			}

		delete m;
		m = new Medicament(newM);
	}

	void remove(int id)
	{
		repoM.deleteElement(id);
	}
};


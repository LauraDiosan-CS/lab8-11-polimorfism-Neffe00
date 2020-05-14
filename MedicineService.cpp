#include "MedicineService.h"

MedicineService::MedicineService()
{}


MedicineService::MedicineService(const RepoFile<Medicament>& repoM)
{
	this->repoM = repoM;
}

MedicineService::MedicineService(const MedicineService& MedicineService)
{
	this->repoM = MedicineService.repoM;
}

MedicineService& MedicineService::operator=(const MedicineService& MedicineService)
{
	if (this != &MedicineService)
	{
		this->repoM = MedicineService.repoM;
	}
	return *this;
}

MedicineService::~MedicineService()
{}

int MedicineService::getNoMedicines()
{
	return repoM.getSize();
}

void MedicineService::addMedicine(int id, string name, int needRecepie, int stockQuantity, string producer)
{
	repoM.addElement(Medicament(id, name, needRecepie, stockQuantity, producer));
}

Medicament MedicineService::getMedicine(int id)
{
	return repoM.getElement(id);
}

vector<Medicament> MedicineService::getMedicines()
{
	return repoM.getElements();
}

void MedicineService::updateMedicine(int id, int newId, string name, int needRecepie, int stockQuantity, string producer)
{
	repoM.updateElement(id, Medicament(newId, name, needRecepie, stockQuantity, producer));
}

void MedicineService::deleteMedicine(int id)
{
	repoM.deleteElement(id);
}
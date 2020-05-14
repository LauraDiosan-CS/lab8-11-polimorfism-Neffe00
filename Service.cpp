//#include "Service.h"
//
//Service::Service()
//{}
//
//Service::Service(const RepoFile<Employee>& repoE, const RepoFile<Medicine>& repoM)
//{
//	this->repoE = repoE;
//	this->repoM = repoM;
//}
//
//Service::Service(const RepoFile<Medicine>& repoM)
//{
//	this->repoM = repoM;
//}
//
//Service::Service(const Service& service)
//{
//	this->repoE = service.repoE;
//	this->repoM = service.repoM;
//}
//
//Service& Service::operator=(const Service& service)
//{
//	if (this != &service)
//	{
//		this->repoE = service.repoE;
//		this->repoM = service.repoM;
//	}
//	return *this;
//}
//
//Service::~Service()
//{}
//
//int Service::getNoEmployees()
//{
//	return repoE.getSize();
//}
//
//void Service::addEmployee(int id, string name, string email, int accessLevel)
//{
//	repoE.addElement(Employee(id, name, email, accessLevel));
//}
//
//Employee Service::getEmployee(int id)
//{
//	return repoE.getElement(id);
//}
//
//vector<Employee> Service::getEmployees()
//{
//	return repoE.getElements();
//}
//
//void Service::updateEmployee(int id, int newId, string name, string email, int accessLevel)
//{
//	repoE.updateElement(id, Employee(newId, name, email, accessLevel));
//}
//
//void Service::deleteEmployee(int id)
//{
//	repoE.deleteElement(id);
//}
//
//int Service::getNoMedicines()
//{
//	return repoM.getSize();
//}
//
//void Service::addMedicine(int id, string name, int needRecepie, int stockQuantity, string producer)
//{
//	repoM.addElement(Medicine(id, name, needRecepie, stockQuantity, producer));
//}
//
//Medicine Service::getMedicine(int id)
//{
//	return repoM.getElement(id);
//}
//
//vector<Medicine> Service::getMedicines()
//{
//	return repoM.getElements();
//}
//
//void Service::updateMedicine(int id, int newId, string name, int needRecepie, int stockQuantity, string producer)
//{
//	repoM.updateElement(id, Medicine(newId, name, needRecepie, stockQuantity, producer));
//}
//
//void Service::deleteMedicine(int id)
//{
//	repoM.deleteElement(id);
//}
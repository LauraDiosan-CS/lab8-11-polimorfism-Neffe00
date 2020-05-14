//#pragma once
//
//#include"Repo.h"
//#include"Repo.cpp"
//#include"RepoFile.h"
//#include"RepoFile.cpp"
//
//class Service
//{
//private:
//	RepoFile<Employee> repoE;
//	RepoFile<Medicine> repoM;
//
//public:
//	Service();
//	Service(const RepoFile<Employee>& repoE, const RepoFile<Medicine>& repoM);
//	Service(const RepoFile<Medicine>& repoM);
//	Service(const Service& service);
//	Service& operator=(const Service& service);
//	~Service();
//
//	int getNoEmployees();
//	void addEmployee(int id, string name, string email, int accessLevel);
//	Employee getEmployee(int id);
//	vector<Employee> getEmployees();
//	void updateEmployee(int id, int newId, string name, string email, int accessLevel);
//	void deleteEmployee(int id);
//
//
//	int getNoMedicines();
//	void addMedicine(int id, string name, int needRecepie, int stockQuantity, string producer);
//	Medicine getMedicine(int id);
//	vector<Medicine> getMedicines();
//	void updateMedicine(int id, int newId, string name, int needRecepie, int stockQuantity, string producer);
//	void deleteMedicine(int id);
//};
//

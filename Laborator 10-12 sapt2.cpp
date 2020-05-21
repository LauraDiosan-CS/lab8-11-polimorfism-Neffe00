#include"Tests.h"
#include"UI.h"

#include<assert.h>

#define CRTDBG_MAP_ALLOC
#include<stdlib.h>
#include<crtdbg.h>

#include<iostream>
using namespace std;

void test_sapt10()
{
	//Repository<Medicament>* repo = new RepositoryFileTXT<Medicament>();
	RepoFile<Medicament>* repo = new RepoFile<Medicament>("dataInM.txt", "dataOutM.txt");

	Medicament* m1 = new Medicament(100, "parasinus", false, 10, "p1");
	Medicament* m2 = new Medicament(200, "ketonal", false, 90, "p2");
	Medicament* m3 = new Medicament(300, "antibiotic", true, 70, "p3");

	repo->add(*m1);
	repo->add(*m2);

	assert(repo->getAll().size() == 2);
	assert(repo->getAll()[0] == *m1);
	assert(repo->getAll()[1] == *m2);
	repo->add(*m3);
	assert(repo->getAll()[2] == *m3);
	
	Medicament m1_new(100, "paracetamol", false, 50, "p1");
	repo->update(m1, m1_new);

	assert(repo->getAll()[0] != *m1);
	assert(repo->getAll()[0] == m1_new);

	repo->remove(200);
	assert(repo->getAll().size() == 2);

	delete m3;
	delete m2;
	delete m1;
	delete repo;
}

void runProgram()
{
	//test_Employee();
	//test_Medicine();
	//test_Repo();
	//test_RepoFile();
	//test_Service();

	test_sapt10();

	RepoFile<Medicament> repository("dataInM.txt", "dataOutM.txt");
	MedicineService* service = new MedicineService{ repository };


	Medicament* m1 = new Medicament(100, "parasinus", false, 10, "p1");
	Medicament* m2 = new Medicament(200, "ketonal", false, 90, "p2");
	Medicament* m3 = new Medicament(300, "antibiotic", true, 70, "p3");

	service->add(*m1);
	service->add(*m2);

	assert(service->getAll().size() == 2);
	assert(service->getAll()[0] == *m1);
	assert(service->getAll()[1] == *m2);
	
	service->add(*m3);
	assert(service->getAll()[2] == *m3);

	assert(service->search("ic").size() == 1);
	assert(service->search("a").size() == 3);

	Medicament m1_new(100, "altceva", false, 50, "p1");
	service->update(m1, m1_new);
	

	//vector<Medicament> meds = service->getMedicines();
	//vector<Medicament> ::iterator it;
	//for (it = meds.begin(); it != meds.end(); it++)
	//	cout << *it << endl;
	//cout << endl;
	//vector<Medicament> searchList = service->search("al");
	//vector<Medicament> ::iterator it2;
	//for (it2 = searchList.begin(); it2 != searchList.end(); it2++)
	//	cout << *it2 << endl;

	assert(service->search("al").size() == 2);
	assert(service->search("al")[0] == *m1);
	assert(service->search("al")[1] == *m2);
	
	service->remove(200);
	assert(service->search("al").size() == 1);
	assert(service->search("al")[0] == *m1);

	delete m3;
	delete m2;
	delete m1;
	delete service;
}

void _runUI()
{
	RepoFile<Employee> repoE("dataInE.txt", "dataOutE.txt");
	RepoFile<Medicament> repoM("dataInM.txt", "dataOutM.txt");
	ServiceEM service(repoE, repoM);

	UI ui(service);
	ui.runUI();
}

int main()
{
	_runUI();
	//runProgram();
	if (_CrtDumpMemoryLeaks() > 0)
		cout << "exista memory leaks" << endl;
	return 0;
}
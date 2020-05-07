#pragma once

#include"Employee.h"
#include"Medicine.h"
#include"RepoFile.h"
#include"RepoFile.cpp"

#include<assert.h>

void test_Employee()
{
	//contructor implicit
	Employee e;
	assert(e.getId() == 0);
	assert(e.getName() == "");
	assert(e.getEmail() == "");
	assert(e.getAccessLevel() == 0);

	//constructor cu parametri
	Employee e1(1, "nume1", "email1", 1);
	assert(e1.getId() == 1);
	assert(e1.getName() == "nume1");
	assert(e1.getEmail() == "email1");
	assert(e1.getAccessLevel() == 1);

	//constructor de copiere
	Employee e2(e1);
	assert(e2.getId() == 1);
	assert(e2.getName() == "nume1");
	assert(e2.getEmail() == "email1");
	assert(e2.getAccessLevel() == 1);

	//set-eri
	e2.setId(2);
	e2.setName("nume2");
	e2.setEmail("email2");
	e2.setAccessLevel(2);
	assert(e2.getId() == 2);
	assert(e2.getName() == "nume2");
	assert(e2.getEmail() == "email2");
	assert(e2.getAccessLevel() == 2);

	//operator==
	assert(!(e1 == e2));

	//operator=
	e1 = e2;
	assert(e1 == e2);

	//operator >> si <<
	//cin >> e1;
	//cout << e1;

	//teste metode IE

	//clone
	Employee* e3 = new Employee(3, "nume3", "email3", 1);
	Employee* ec = e3->clone();
	assert(ec != e3);

	Employee* e4 = new Employee(4, "nume4", "email4", 1);
	Employee* e5 = new Employee(5, "nume5", "email5", 0);
	
	//equals
	assert(e4->equals(e4));
	assert(!(e4->equals(e5)));

	//compareTo
	assert(e4->compareTo(e5) == 1);

	//toString
	assert(e4->toString() == "Employee: 4 nume4 email4 1");

	//copy
	e4->copy(e5);
	//cout << e4->toString() << endl;
	assert(e4->equals(e5));

	delete ec;
	delete e3;
	delete e4;
	delete e5;

	cout << "Employee tests are ok!" << endl;
}

/*
void test_Medicine()
{
	//contructor implicit
	Medicine m;
	assert(m.getId() == 0);
	assert(m.getName() == "");
	assert(m.getNeedRecepie() == false);
	assert(m.getStockQuantity() == 0);
	assert(m.getProducer() == "");

	//constructor cu parametri
	Medicine m1(1, "nume1", true, 10, "producator1");
	assert(m1.getId() == 1);
	assert(m1.getName() == "nume1");
	assert(m1.getNeedRecepie() == 1);
	assert(m1.getStockQuantity() == 10);
	assert(m1.getProducer() == "producator1");

	//constructor de copiere
	Medicine m2(m1);
	assert(m2.getId() == 1);
	assert(m2.getName() == "nume1");
	assert(m2.getNeedRecepie() == 1);
	assert(m2.getStockQuantity() == 10);
	assert(m2.getProducer() == "producator1");

	//set-eri
	m2.setId(2);
	m2.setName("nume2");
	m2.setNeedRecepie(false);
	m2.setStockQuantity(20);
	m2.setProducer("producator2");
	assert(m2.getId() == 2);
	assert(m2.getName() == "nume2");
	assert(m2.getNeedRecepie() == false);
	assert(m2.getStockQuantity() == 20);
	assert(m2.getProducer() == "producator2");

	//operator==
	assert(!(m1 == m2));

	//operator=
	m1 = m2;
	assert(m1 == m2);

	//operator >> si <<
	//cin >> m1;
	//cout << m1;


	//teste metode IE

	//clone
	Medicine* m3 = new Medicine(3, "nume3", 0, 30, "producator3");
	Medicine* mc = m3->clone();
	assert(mc != m3);

	Medicine* m4 = new Medicine(4, "nume4", 1, 40, "producator4");
	Medicine* m5 = new Medicine(5, "nume5", 0, 50, "producator5");

	//equals
	m4->equals(m4);
	assert(m4->equals(m4));
	assert(!(m4->equals(m5)));

	//compareTo
	assert(m5->compareTo(m4) == 1);

	//toString
	assert(m4->toString() == "Medicine: 4 nume4 1 40 producator4");

	//copy
	m4->copy(m5);
	//cout << m4->toString() << endl;
	assert(m4->equals(m5));

	delete mc;
	delete m3;
	delete m4;
	delete m5;

	cout << "Medicine tests are ok!" << endl;
}
*/
/*
void test_Repo()
{
	Repo<Medicine> repo;
	Medicine m1(1, "nume1", true, 10, "producator1");
	Medicine m2(2, "nume2", true, 20, "producator2");

	repo.addElement(m1);
	repo.addElement(m2);
	assert(repo.noElements() == 2);

	vector<Medicine> elements = repo.getElements();
	vector<Medicine> ::iterator it;
	for (it = elements.begin(); it != elements.end(); it++)
		cout << *it;
	cout << endl;
	

	assert(repo.getElement(1) == m1);
	assert(repo.getElement(2) == m2);
	
	Medicine m3(2, "nume3", true, 30, "producator3");

	repo.updateElement(2, m3);
	assert(repo.getElement(2) == m3);

	repo.deleteElement(1);
	repo.deleteElement(2);
	assert(repo.noElements() == 0);

	cout << "Repo tests are ok!" << endl;
}
*/

/*
void test_RepoFile()
{
	RepositoryFileTXT<Medicine> repo("dataIn.txt", "dataOut.txt");

	vector<Medicine> elements = repo.getElements();
	vector<Medicine> ::iterator it;
	for (it = elements.begin(); it != elements.end(); it++)
		cout << *it << endl;
	cout << endl;

}
*/
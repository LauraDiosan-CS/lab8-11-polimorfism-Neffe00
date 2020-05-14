#pragma once

#include"Service.h"

#include<assert.h>

void test_Employee()
{
	/*
		Employee:
			int id
			string name
			string email
			int accessLevel
	*/

	//default contructor
	Employee e;
	assert(e.getId() == 0);
	assert(e.getName() == "");
	assert(e.getEmail() == "");
	assert(e.getAccessLevel() == 0);

	//parameters constructor
	Employee e1(1, "nume1", "email1", 1);
	assert(e1.getId() == 1);
	assert(e1.getName() == "nume1");
	assert(e1.getEmail() == "email1");
	assert(e1.getAccessLevel() == 1);

	//copy constructor
	Employee e2(e1);
	assert(e2.getId() == 1);
	assert(e2.getName() == "nume1");
	assert(e2.getEmail() == "email1");
	assert(e2.getAccessLevel() == 1);

	//set
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
	e2 = e1;
	assert(e1 == e2);

	//operator >> si <<
	//cin >> e1;
	//cout << e1;

	/*
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
	*/
	cout << "Employee tests are ok!" << endl;
}

void test_Medicine()
{
	/*
		Medicine:
			int id
			string name
			int needRecipie
			int stockQuantity
			string producer
	*/
	
	//default contructor
	Medicine m;
	assert(m.getId() == 0);
	assert(m.getName() == "");
	assert(m.getNeedRecepie() == 0);
	assert(m.getStockQuantity() == 0);
	assert(m.getProducer() == "");

	//paramaters constructor
	Medicine m1(1, "nume1", 0, 10, "prod1");
	assert(m1.getId() == 1);
	assert(m1.getName() == "nume1");
	assert(m1.getNeedRecepie() == 0);
	assert(m1.getStockQuantity() == 10);
	assert(m1.getProducer() == "prod1");

	//copy contructor
	Medicine m2(m1);
	assert(m2.getId() == 1);
	assert(m2.getName() == "nume1");
	assert(m2.getNeedRecepie() == 0);
	assert(m2.getStockQuantity() == 10);
	assert(m2.getProducer() == "prod1");

	//set
	m2.setId(2);
	m2.setName("nume2");
	m2.setNeedRecepie(1);
	m2.setStockQuantity(20);
	m2.setProducer("prod2");

	assert(m2.getId() == 2);
	assert(m2.getName() == "nume2");
	assert(m2.getNeedRecepie() == 1);
	assert(m2.getStockQuantity() == 20);
	assert(m2.getProducer() == "prod2");

	//operator==
	assert(!(m1 == m2));

	//operator=
	m2 = m1;
	assert(m1 == m2);

	//>> <<
	/*cin >> m;
	cout << m;*/

	cout << "Medicine tests are ok!" << endl;
}


/*
void test_Repo()
{
	Repo<Employee> repo;

	//add
	Employee e1(1, "nume1", "email1", 1);
	Employee e2(2, "nume2", "email2", 2);
	repo.addElement(e1);
	repo.addElement(e2);

	assert(repo.getSize() == 2);
	assert(repo.getElement(1) == e1);
	assert(repo.getElement(2) == e2);

	//get elements
	vector<Employee> v = repo.getElements();
	vector<Employee>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
		cout << *it;

	//update
	Employee e3(3, "nume3", "email3", 3);
	repo.updateElement(2, e3);
	assert(repo.getElement(3)==e3);

	//delete
	repo.deleteElement(1);
	repo.deleteElement(3);
	assert(repo.getSize() == 0);

	cout << "Repo tests are ok!" << endl;
}
*/

/*
void test_RepoFile()
{
	RepoFile<Employee> repoF("dataIn.txt", "dataOut.txt");

	//add
	Employee e1(1, "nume1", "email1", 1);
	Employee e2(2, "nume2", "email2", 2);
	repoF.addElement(e1);
	repoF.addElement(e2);

	assert(repoF.getSize() == 2);
	assert(repoF.getElement(1) == e1);
	assert(repoF.getElement(2) == e2);

	//get elements
	vector<Employee> v = repoF.getElements();
	vector<Employee>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
		;// cout << *it;

	//update
	Employee e3(3, "nume3", "email3", 3);
	repoF.updateElement(2, e3);
	assert(repoF.getElement(3) == e3);

	//delete
	repoF.deleteElement(1);
	repoF.deleteElement(3);
	assert(repoF.getSize() == 0);

	repoF.addElement(e1);
	repoF.addElement(e2);

	cout << "repoFFile tests are ok!" << endl;
}
*/
/*
void test_Service()
{
	RepoFile<Employee> repoE("dataInE.txt", "dataOutE.txt");
	RepoFile<Medicine> repoM("dataInM.txt", "dataOutM.txt");

	Service service(repoE, repoM);
	
	service.addEmployee(1, "nume1", "email1", 1);
	service.addEmployee(2, "nume2", "email2", 2);
	assert(service.getNoEmployees() == 2);

	vector<Employee> v = service.getEmployees();
	vector<Employee>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
		cout << *it << endl;

	service.updateEmployee(2, 3, "nume3", "email3", 3);
	assert(service.getEmployee(3).getName() == "nume3");

	service.deleteEmployee(1);
	service.deleteEmployee(3);
	assert(service.getNoEmployees() == 0);
	
	service.addMedicine(1, "nume1", 0, 10, "prod1");

	cout << "ServiceEmployee tests are ok!" << endl;
}
*/
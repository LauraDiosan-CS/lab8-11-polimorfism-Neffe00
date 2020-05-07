#include"Tests.h"
#include"Repo.h"

#define CRTDBG_MAP_ALLOC
#include<stdlib.h>
#include<crtdbg.h>


void test()
{
	Repository<Medicament>* repo = new RepositoryFileTXT<Medicament>();
	Medicament* m1 = new Medicament(100, "parasinus", false, 10, "p1");
	Medicament* m2 = new Medicament(200, "ketonal", false, 90, "p2");
	Medicament* m3 = new Medicament(300, "antibiotic", true, 70, "p3");


	repo->add(m1);
	repo->add(m2);

	assert(repo->getAll().size() == 2);
	
	assert(*repo->getAll()[0] == *m1);
	assert(*repo->getAll()[1] == *m2);
	
	repo->add(m3);
	assert( *repo->getAll()[2] == *m3 );

	Medicament m1_new(100, "paracetamol", false, 50, "p1");
	repo->update(m1, &m1_new);

	assert(*repo->getAll()[0] != *m1);
	assert(*repo->getAll()[0] == m1_new);

	repo->del(200);
	assert(repo->getAll().size() == 2);
}

void runProgram()
{
	//test_Employee();
	//test_Medicine();
	//test_Repo();
	//test_RepoFile();

	test();
}

int main()
{
	runProgram();
	if (_CrtDumpMemoryLeaks() > 0)
		cout << "There are memory leaks!!!!!" << endl;

	return 0;
}
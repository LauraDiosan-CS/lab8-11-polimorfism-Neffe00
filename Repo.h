#pragma once

#include<vector>
#include<iterator>
using namespace std;

#include"Employee.h"
#include"Medicine.h"

template <class T>
class Repo
{
protected:
	vector<T> elements;
public:
	Repo();
	Repo(const Repo& r);
	~Repo();
	Repo& operator=(const Repo& r);

	int getSize();
	void addElement(const T& element);
	T getElement(int id);
	vector<T> getElements();
	void updateElement(int id, const T& newElement);
	void deleteElement(int id);
};
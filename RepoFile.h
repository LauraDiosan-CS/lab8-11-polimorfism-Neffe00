#pragma once

#include"Repo.h"

#include<iostream>
using namespace std;

template <class T>
class RepositoryFileTXT : public Repository<T>
{

private:
	char* fileNameIn;
	char* fileNameOut;

public:
	RepositoryFileTXT();
	RepositoryFileTXT(const char* fileNameIn, const char* fileNameOut);
	RepositoryFileTXT(const RepositoryFileTXT& r);
	~RepositoryFileTXT();

	void add(const T* element);
	void update(T* element,const T* newElement);
	void del(int id);

	void loadFromFile();
	void saveToFile();

	RepositoryFileTXT& operator = (const RepositoryFileTXT& r)
	{
		this->elements = r.elements;

		this->fileNameIn = new char[strlen(r.fileNameIn) + 1];
		strcpy_s(this->fileNameIn, strlen(r.fileNameIn) + 1, r.fileNameIn);

		this->fileNameOut = new char[strlen(r.fileNameOut) + 1];
		strcpy_s(this->fileNameOut, strlen(r.fileNameOut) + 1, r.fileNameOut);

		return*this;
	}
};
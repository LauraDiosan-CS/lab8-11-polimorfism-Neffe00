#include"RepoFile.h"

#include<iostream>
using namespace std;

#include<vector>
#include<iterator>

#include<fstream>


template <class T>
RepoFile<T>::RepoFile()
{
	this->fileNameIn = NULL;
	this->fileNameOut = NULL;
}

template <class T>
RepoFile<T>::RepoFile(const char* fileNameIn, const char* fileNameOut)
{
	this->fileNameIn = new char[strlen(fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);

	this->fileNameOut = new char[strlen(fileNameOut) + 1];
	strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);

	this->loadFromFile();
}

template<class T>
RepoFile<T>::RepoFile(const RepoFile& r)
{
	this->elements = r.elements;

	this->fileNameIn = new char[strlen(r.fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(r.fileNameIn) + 1, r.fileNameIn);

	this->fileNameOut = new char[strlen(r.fileNameOut) + 1];
	strcpy_s(this->fileNameOut, strlen(r.fileNameOut) + 1, r.fileNameOut);

	this->loadFromFile();
}

template<class T>
RepoFile<T>& RepoFile<T>::operator = (const RepoFile& r)
{
	this->elements = r.elements;

	this->fileNameIn = new char[strlen(r.fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(r.fileNameIn) + 1, r.fileNameIn);

	this->fileNameOut = new char[strlen(r.fileNameOut) + 1];
	strcpy_s(this->fileNameOut, strlen(r.fileNameOut) + 1, r.fileNameOut);

	return*this;
}

template <class T>
RepoFile<T>::~RepoFile()
{
	if (this->fileNameIn != NULL)
	{
		delete[] this->fileNameIn;
		this->fileNameIn = NULL;
	}

	if (this->fileNameOut != NULL)
	{
		delete[] this->fileNameOut;
		this->fileNameOut = NULL;
	}
}

template <class T>
void RepoFile<T>::addElement(T element)
{
	Repo<T>::addElement(element);
	this->saveToFile();
}

template <class T>
void RepoFile<T>::updateElement(int id, T newElement)
{
	Repo<T>::updateElement(id, newElement);
	this->saveToFile();
}

template <class T>
void RepoFile<T>::deleteElement(int id)
{
	Repo<T>::deleteElement(id);
	this->saveToFile();
}

template <class T>
void RepoFile<T>::setFileNameIn(const char* fileNameIn)
{
	if (this->fileNameIn)
	{
		delete[] this->fileNameIn;
		this->fileNameIn = NULL;
	}

	this->fileNameIn = new char[strlen(fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
}

template <class T>
void RepoFile<T>::setFileNameOut(const char* fileNameOut)
{
	if (this->fileNameOut)
	{
		delete[] this->fileNameOut;
		this->fileNameOut = NULL;
	}

	this->fileNameOut = new char[strlen(fileNameOut) + 1];
	strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);
}


template <class T>
void RepoFile<T>::saveToFile()
{
	if (this->fileNameOut != NULL)
	{
		ofstream f(this->fileNameOut);

		vector<T> elements = this->elements;
		class vector<T> ::iterator it;

		for (it = elements.begin(); it != elements.end(); it++)
		{
			//cout << *it;
			f << *it;
		}

		f.close();
	}
}

template <class T>
void RepoFile<T>::loadFromFile()
{
	if (this->fileNameIn != NULL)
	{
		this->elements.clear();
		ifstream f(this->fileNameIn);

		T element;
		while (f >> element)
		{
			//cout << element;
			this->elements.push_back(element);
		}

		f.close();
	}
}
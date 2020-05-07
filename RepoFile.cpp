#include"RepoFile.h"

#include<vector>
#include<iterator>
#include<fstream>

template <class T>
RepositoryFileTXT<T>::RepositoryFileTXT()
{
	this->fileNameIn = NULL;
	this->fileNameOut = NULL;
}

template <class T>
RepositoryFileTXT<T>::RepositoryFileTXT(const char* fileNameIn, const char* fileNameOut)
{
	this->fileNameIn = new char[strlen(fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);

	this->fileNameOut = new char[strlen(fileNameOut) + 1];
	strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);

	this->loadFromFile();
}

template<class T>
RepositoryFileTXT<T>::RepositoryFileTXT(const RepositoryFileTXT& r)
{
	this->elements = r.elements;

	this->fileNameIn = new char[strlen(r.fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(r.fileNameIn) + 1, r.fileNameIn);

	this->fileNameOut = new char[strlen(r.fileNameOut) + 1];
	strcpy_s(this->fileNameOut, strlen(r.fileNameOut) + 1, r.fileNameOut);

	this->loadFromFile();
}

template <class T>
RepositoryFileTXT<T>::~RepositoryFileTXT()
{
	saveToFile();
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
void RepositoryFileTXT<T>::add(const T* element)
{
	this->elements.push_back(*element);
	this->saveToFile();
}

template <class T>
void RepositoryFileTXT<T>::update(T* element,const T* newElement)
{
	typename vector<T> ::iterator it;
	for (it = this->elements.begin(); it != this->elements.end(); it++)
		if ((*it).getId() == (*element).getId())
		{
			*it = *newElement;
			break;
		}

	this->saveToFile();
}

template <class T>
void RepositoryFileTXT<T>::del(int id)
{
	typename vector<T> ::iterator it;
	for (it = this->elements.begin(); it != this->elements.end(); it++)
		if ((*it).getId() == id)
		{
			this->elements.erase(it);
			break;
		}
	this->saveToFile();
}


template <class T>
void RepositoryFileTXT<T>::saveToFile()
{
	if (this->fileNameOut != NULL)
	{
		ofstream f(this->fileNameOut);

		vector<T> elements = this->elements;
		typename vector<T> ::iterator it;

		for (it = elements.begin(); it != elements.end(); it++)
		{
			//cout << *it;
			f << *it;
		}

		f.close();
	}
}

template <class T>
void RepositoryFileTXT<T>::loadFromFile()
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
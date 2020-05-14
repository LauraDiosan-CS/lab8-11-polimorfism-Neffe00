#include "Repo.h"

template <class T>
Repo<T>::Repo()
{}

template <class T>
Repo<T>::Repo(const Repo& r)
{
	elements = r.elements;
}

template <class T>
Repo<T>::~Repo()
{}

template <class T>
Repo<T>& Repo<T>::operator=(const Repo& r)
{
	elements = r.elements;
	return *this;
}

template <class T>
int Repo<T>::getSize()
{
	return elements.size();
}

template <class T>
void Repo<T>::addElement(const T& element)
{
	elements.push_back(element);
}

template <class T>
T Repo<T>::getElement(int id)
{
	class vector<T>::iterator it;
	for (it = elements.begin(); it != elements.end(); it++)
		if (it->getId() == id)
			return *it;
	
}

template <class T>
vector<T> Repo<T>::getElements()
{
	return elements;
}

template <class T>
void Repo<T>::updateElement(int id, const T& newElement)
{
	class vector<T>::iterator it;
	for(it=elements.begin() ; it!=elements.end() ; it++)
		if (it->getId() == id)
		{
			*it = newElement;
			break;
		}
}

template <class T>
void Repo<T>::deleteElement(int id)
{
	class vector<T>::iterator it;
	for(it=elements.begin() ; it!=elements.end() ; it++)
		if (it->getId() == id)
		{
			elements.erase(it);
			break;
		}
}

#pragma once

#include<vector>
#include<iterator>
using namespace std;

template <class T>
class Repository
{
public:
	vector<T> elements;
public:
	Repository()
	{
		this->elements.clear();
	}
	Repository(const Repository& r)
	{
		this->elements = r.getElements();
	}
	~Repository()
	{
		this->elements.clear();
	}

	int noElements()
	{
		return this->elements.size();
	}

	virtual void add(const T* element)
	{
		this->elements.push_back(element);
	}

	T getElement(int id)
	{
		typename vector<T> ::iterator it;

		for (it = this->elements.begin(); it != this->elements.end(); it++)
			if ((*it).getId() == id)
				return *it;
	}

	vector<T*> getAll()
	{
		typename vector<T*> v;
		//this->elements.clear();
		
		for (int i = 0; i < this->elements.size(); i++)
			v.push_back( this->elements[i].clone() );

		//typename vector<T> ::iterator it;
		//for (it = this->elements.begin(); it != this->elements.end(); it++)
			//v.push_back( it );

		return v;
	}

	virtual void update(T* element,const T* newElement)
	{
		typename vector<T> ::iterator it;
		for (it = this->elements.begin(); it != this->elements.end(); it++)
			if ((*it).getId() == (*element).getId() )
			{
				*it = *newElement;
				break;
			}
	}

	virtual void del(int id)
	{
		typename vector<T> ::iterator it;
		for (it = this->elements.begin(); it != this->elements.end(); it++)
			if ((*it).getId() == id)
			{
				this->elements.erase(it);
				break;
			}
	}
};
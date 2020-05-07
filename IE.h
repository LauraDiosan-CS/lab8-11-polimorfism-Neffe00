#pragma once

#include<iostream>
using namespace std;
#include<string>

class IE {
public:
	virtual IE* clone() = 0;
	virtual void copy(IE*) = 0;
	virtual bool equals(IE*) = 0;
	virtual int compareTo(IE*) = 0;
	virtual string toString() = 0;
	virtual ~IE() {};
};

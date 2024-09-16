#pragma once
#include <string>
#include <memory>
#include <iostream>
#include "io.h"

class Operation
{
	string m_type;
public:
	
	Operation(const string);
	virtual ~Operation() = default;

	string getName() const;
	void print(const string&) const;

	//the calculate function has a prinitng function but we dont need to print
	// always so it gets a bool variable which decides if to print or not
	virtual string calculate(const string,const bool) const = 0;
};
#pragma once
#include "Operation.h"

class Substring:public Operation
{
	int m_startIndex, m_length;

public:

	Substring(const int, const int);
	virtual string calculate(const string, const bool) const override;
};
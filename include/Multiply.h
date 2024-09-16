#pragma once
#include "Operation.h"
class Multiply:public Operation
{
	int m_multiple;
	std::shared_ptr<Operation> m_theOperation;

public:

	Multiply(int , std::shared_ptr<Operation>&);

	virtual string calculate(const string, const bool)const override;

};
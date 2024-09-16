#pragma once
#include "Operation.h"

class Composite:public Operation
{
private:
	std::shared_ptr<Operation> m_firstOperation;
	std::shared_ptr<Operation> m_secondOperation;

public:

	Composite(std::shared_ptr<Operation>&, std::shared_ptr<Operation>&);

	virtual string calculate(const string, const bool) const override;
};
#pragma once
#include "Operation.h"

class Add : public Operation
{

	std::shared_ptr<Operation> m_firstOperation;
	std::shared_ptr<Operation> m_secondOperation;

public:

	Add(std::shared_ptr<Operation>&, std::shared_ptr<Operation>&);

	virtual string calculate(const string, const bool) const override;
};
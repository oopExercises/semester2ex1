#pragma once
#include "Operation.h"
class Id : public Operation
{

public:
	Id() : Operation("id") {};

	virtual string calculate(const string, const bool) const override;
};
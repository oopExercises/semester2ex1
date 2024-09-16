#pragma once
#include "Operation.h"

class Reverse : public Operation
{
public:
	Reverse() : Operation("reverse") {};

	virtual string calculate(const string, const bool) const override;
};
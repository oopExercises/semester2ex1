#pragma once
#include "Operation.h"

class SwapCase : public Operation
{
public:
	SwapCase() : Operation("swapCase") {};

	virtual string calculate(const string, const bool) const override;
};
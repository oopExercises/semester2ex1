#include "Composite.h"

Composite::Composite(std::shared_ptr<Operation>& op1, std::shared_ptr<Operation>& op2) : m_firstOperation(op1), m_secondOperation(op2),
Operation("(" + op1->getName() + "  ->  " + op2->getName() + ")")
{
}

string Composite::calculate(const string str, const bool b)const
{
	if (b)
	{
		print(str);
	}
	auto resultString1 = m_firstOperation->calculate(str,0);
	auto resultString2 = m_secondOperation->calculate(resultString1,0);

	return resultString2;
}

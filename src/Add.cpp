#include "Add.h"

Add::Add(std::shared_ptr<Operation>& op1, std::shared_ptr<Operation>& op2) : m_firstOperation(op1), m_secondOperation(op2),
Operation("(" + op1->getName() + " + " + op2->getName() + ")")
{
}

string Add::calculate(const string str, const bool b)const
{
	if (b)
	{
		print(str);
	}
	auto resultString1 = m_firstOperation->calculate(str, 0);
	auto resultString2 = m_secondOperation->calculate(str, 0);
	auto finalStr = resultString1 + resultString2;

	return 	 finalStr;
		
}

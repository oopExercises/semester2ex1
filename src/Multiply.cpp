#include "Multiply.h"

Multiply::Multiply(int n, std::shared_ptr<Operation>& op) : m_multiple(n), m_theOperation(op),
Operation("(" + op->getName()  + " * " + std::to_string(n) + ")")
{
}

string Multiply::calculate(const string str, const bool b)const
{
	if (b)
	{
		print(str);
	}
	string s = "";
	for(int i =0 ;i<m_multiple;i++)
	{ 
		s += m_theOperation->calculate(str, 0);
	}
	return s;
}

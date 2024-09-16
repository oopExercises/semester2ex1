#include "Substring.h"



Substring::Substring(const int num1, const int num2): m_startIndex(num1), m_length(num2),
Operation("substr " + std::to_string(num1) + "," + std::to_string(num2))
{
}

string Substring::calculate(const string str, const bool b)const
{
	if (b)
	{
		print(str);
	}

	return str.substr(m_startIndex, m_length);
}

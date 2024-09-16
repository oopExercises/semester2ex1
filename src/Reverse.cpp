#include "Reverse.h"

string Reverse::calculate(const string str, const bool b)const
{
	if (b)
	{
		print(str);
	}

	string reverseStr = str ;
	for (int i = 0, j = str.size() - 1; i < str.size() && j> -1; i++, j--)
	{
		reverseStr[i] = str[j];
	}

	return reverseStr;
	
}
